#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#include <string.h>
#include <fstream>
#include <string>

using namespace std;

template <typename T> class QuadTree {

    public:
        T pinfo;
        QuadTree<T> **sons;
        QuadTree<T> *parent, *root;
        int nr_sons;        ///nr. de sons creati (cu new)
        ///incomplete sons arata daca vectorul de fii al quad tree ului care il consulta este plin sau nu
        int incomplete_sons;    ///imi da okay ul in caz ca citesc un parint si ulterior va trebui sa ii adaug kids
        int level;
        int number;
        int pixels;

        QuadTree()
        {
            sons = new QuadTree<T>*[4];
            pinfo = NULL;
            parent = NULL;
            root = NULL;
            nr_sons = 0;
            incomplete_sons = 0;
            level = 0;
            number = 0;     ///creat pentru afisare; al cate lea fiu este
            pixels = 0;
        }

        ~QuadTree()
        {
            delete_quad();
        }

        void delete_quad() {
            if (nr_sons == 0) {
                delete[] sons;
            } else {
                for (int i = 0; i < nr_sons; ++i) {
                    sons[i]->delete_quad();
                }
            }
            if (pinfo == 'p') {
                delete[] sons;
            }
        }

        void calculate_pixels() {

            if (nr_sons == 0) {
               if (pinfo == 'b') {
                    root->pixels += ((32 / (2 * level)) * (32 / (2 * level)));
                }
            } else {
                for (int i = 0; i < nr_sons; ++i) {
                    sons[i]->calculate_pixels();
                }
            }
        }

        int get_pixels() {
            if (nr_sons == 0) {
                 if (pinfo == 'b') {
                    return 1024;
                 } else {
                     return 0;
                 }
            }
            calculate_pixels();
            return root->pixels;
        }

        void print_quad() {
            if (pinfo == 'p') {
                cout <<"Level: " << level << " -> Nodul: !<" << pinfo
                    << ">! al " << number << "-lea fiu al nodului <" << parent->pinfo
                    << "> de la level " << parent->level << "." <<endl;
            }
            if (nr_sons == 0) {
                cout <<"Level: " << level << " -> Nodul: !<" << pinfo
                    << ">! al " << number << "-lea fiu al nodului <" << parent->pinfo
                    << "> de la level " << parent->level << "." <<endl;
            } else {
                for (int i = 0; i < nr_sons; ++i) {
                    sons[i]->print_quad();
                }
            }
        }

        void insert_elem(T info) {
            ///inserare root
            if (parent == NULL) {
                parent = this;
                root = this;
                pinfo = info;
                ///vectorul de fii este setat incomplet
                incomplete_sons = 1;
                return;
            }

            ///adaugarea primului fiu al oricarui nod
            if (nr_sons == 0) {
                ///creem fiul si il initializam
                sons[nr_sons] = new QuadTree<T>;
                sons[nr_sons]->pinfo = info;
                sons[nr_sons]->parent = this;
                ///root-ul se propaga, e acelasi la toate
                sons[nr_sons]->root = this->root;

                ///daca este la randul lui parinte
                ///ii setam vectorul de fii incomplet
                if (info == 'p') {
                    sons[nr_sons]->incomplete_sons = 1;
                }
                ///setam nivelul la care se afla
                sons[nr_sons]->level = sons[nr_sons]->parent->level + 1;
                ///setam al catelea fiu e
                sons[nr_sons]->number = nr_sons + 1;
                ///crestem numarl de copii al nodului curent pentru a adauga
                ///urmatorul copil unde trebuie in lista data viitoare
                nr_sons++;
                return;
            }

            ///verificam daca nodul trebuie adaugat ca fiu
            ///al nodului curent sau nu
            if (nr_sons < 4) {
                ///daca "fratele" sau precedent are lista de fii
                ///incompleta trebuie adaugat acolo printr-un apel
                ///recursiv pe frate
                if (sons[nr_sons - 1]->incomplete_sons) {
                    sons[nr_sons - 1]->insert_elem(info);
                } else {
                    ///daca trebuie adaugat ca fiu al nodului curent
                    ///creem nodul si il initializam
                    sons[nr_sons] = new QuadTree<T>;
                    sons[nr_sons]->pinfo = info;
                    sons[nr_sons]->parent = this;
                    sons[nr_sons]->root = this->root;
                    ///daca fiul va fi la randul lui parinte ii setam
                    ///ca fiind incompleta lista de fii
                    if (info == 'p') {
                        sons[nr_sons]->incomplete_sons = 1;
                    }
                    ///setam levelul la care se afla
                    sons[nr_sons]->level = sons[nr_sons]->parent->level + 1;
                    ///setam al catelea fiu e
                    sons[nr_sons]->number = nr_sons + 1;
                    ///crestem numarul de fii in lista de fii a nodului curent
                    ///pentru a-l adauga pe urmatorul in continuare
                    nr_sons++;
                }
            ///daca lista de fii a nodului este plina
            } else if (nr_sons == 4) {
                ///verificam daca ultimul nod din lista era si el parinte
                if (sons[nr_sons - 1]->incomplete_sons) {
                    ///daca da adaugam in lista lui de copii a fiului
                    sons[nr_sons - 1]->insert_elem(info);
                } else {
                    ///daca nu setam nodul ca avand completata lista de copii
                    incomplete_sons = 0;
                    parent->insert_elem(info);
                }
            }
        }
};

///creeare quad
    QuadTree<char>* create_quad(string input) {

        QuadTree<char> *tree = new QuadTree<char>;
        int n = input.length();
        for (int i = 0; i < n; ++i) {
            tree->insert_elem(input[i]);
        }
        return tree;
    }

    void combine(QuadTree<char> *first_tree, QuadTree<char> *second_tree, QuadTree<char>* &result) {

        if (first_tree->nr_sons == 0 || second_tree->nr_sons == 0) {
            if (first_tree->pinfo == 'b') {
                result = first_tree;
                return;
            } else if (second_tree->pinfo == 'b'){
                result = second_tree;
                return;
            } else if (first_tree->pinfo == 'w' && second_tree->pinfo == 'w') {
                result = first_tree;
                return;
            } else if (first_tree->pinfo == 'w' && second_tree->pinfo == 'p') {
                result = second_tree;
                return;
            } else if (first_tree->pinfo == 'p' && second_tree->pinfo == 'w') {
                result = first_tree;
                return;
            }

        } else {
            result->insert_elem('p');

            for (int i = 0; i < 4; ++i) {

                combine(first_tree->sons[i], second_tree->sons[i], result->sons[i]);
            }
        }
        //return result;
    }

    int main() {

        ifstream f("date.txt");

        string input1, input2;
        getline(f, input1);
        getline(f, input2);

        QuadTree<char> *tree1 = create_quad(input1);

        tree1->print_quad();

        cout << endl << "Number of pixels: " << tree1->get_pixels() << "px \n";
        cout << endl;

        QuadTree<char> *tree2 = create_quad(input2);

        tree2->print_quad();

        cout << endl << "Number of pixels: " << tree2->get_pixels() << "px \n";
        cout << endl;

        ///I tried to do the combining of two images, but it doesn't work properly

        cout << endl << "The combining of the images doesn't work. Sorry :( \n\n";

        QuadTree<char> *result = new QuadTree<char>();

        combine(tree1, tree2, result);
        result->print_quad();

        f.close();

        return 0;
    }
