#include <iostream>
#include <fstream>
#include <utility>
#include <map>
#include <algorithm>
#include <vector>
#include <queue>

using namespace std;

typedef struct
{
    long long d;
    long long t;
    long long r;
} d_t_r_;

typedef struct
{
    long long score;
    long long distance;
} score_distance_;

long long optimal_equip(int R, int N, int E, vector<d_t_r_> d_t_r)
{
    long long best_solution = -1;
    long long curr_distance, curr_solution, score;

    map<long long, long long> distance_score;

    score_distance_ car_tmp;

    car_tmp.score = 0;
    car_tmp.distance = R;

    queue<score_distance_> cars;

    cars.push(car_tmp);

    distance_score[R] = 0;

    long long d, t, r;
    d_t_r_ d_t_r_tmp;

    int cars_size;
    score_distance_ new_car_tmp;

    queue<score_distance_> new_cars;

    //the loop for iterating through the cars that still have energy left
    for (int i = 0; i < E; ++i)
    {
        d_t_r_tmp = d_t_r[i];
        d = d_t_r_tmp.d;
        t = d_t_r_tmp.t;
        r = d_t_r_tmp.r;

        cars_size = cars.size();

        //checking if I already achived a better time for replacing all the cars
        //than the time it takes to recharge from the i-th car
        if (best_solution != -1 && t > best_solution)
        {
            continue;
        }

        //the loop for iterating through the cars I can currently recharge from
        for (int car_idx = 0; car_idx < cars_size; ++car_idx)
        {
            car_tmp = cars.front();
            cars.pop();

            curr_distance = car_tmp.distance;

            //checking if we can reach the new car with our current solution (car)
            if (curr_distance < d)
            {
                continue;
            }
            else
            {   //adding the time to recharge from the new car to the time we had already
                //accumulatead reaching the new car
                curr_solution = car_tmp.score + t;

                //checking if we don't already have achieved a better time
                if (best_solution != -1 && curr_solution > best_solution)
                {
                    cars.push(car_tmp);
                    continue;
                }

                //updating the distance to reach the furthest car from the new
                //car which we recharged from 
                curr_distance = d + r;

                //if I have replaced all the cars I update the best score if necessary
                if (curr_distance >= N)
                {
                    if (best_solution == -1 || curr_solution < best_solution)
                    {
                        best_solution = curr_solution;
                    }
                }
                else
                {
                    //if I had ever reached the current distance, I check 
                    //if I've ever made it with a better score
                    if (distance_score[curr_distance])
                    {
                        score = distance_score[curr_distance];
                        
                        //if not, I update the best_score in the map, and prepare 
                        //the new solution to be pushed in the cars (the possible 
                        //solutions) queue
                        if (curr_solution < score)
                        {
                            distance_score[curr_distance] = curr_solution;

                            new_car_tmp.distance = curr_distance;
                            new_car_tmp.score = curr_solution;

                            new_cars.push(new_car_tmp);
                        }
                    }
                    //else it means I reached a new distance with a new score
                    else
                    {
                        //I update the best_score in the map, and prepare 
                        //the new solution to be pushed in the cars (the possible 
                        //solutions) queue
                        distance_score[curr_distance] = curr_solution;

                        new_car_tmp.distance = curr_distance;
                        new_car_tmp.score = curr_solution;

                        new_cars.push(new_car_tmp);
                    }
                }
                //I put back the current solution in the cars queue
                if (distance_score[car_tmp.distance] == car_tmp.score)
                {
                    cars.push(car_tmp);
                }
            }
        }

        //I insert the new possible solutions in the cars queue
        while (!new_cars.empty())
        {
            new_car_tmp = new_cars.front();
            new_cars.pop();

            cars.push(new_car_tmp);
        }
    }

    return best_solution;
}

int main()
{
    // opening input file for reading
    ifstream input_file("ice.in");

    if (!input_file.is_open())
    {

        cerr << "Could not open the input file" << endl;

        return EXIT_FAILURE;
    }

    // reading R, N and E from the input file
    int R, N, E;

    input_file >> R;
    input_file >> N;
    input_file >> E;

    // reading ...
    vector<d_t_r_> d_t_r;
    d_t_r_ tmp;

    for (int i = 0; i < E; ++i)
    {
        input_file >> tmp.d;
        input_file >> tmp.t;
        input_file >> tmp.r;
        d_t_r.push_back(tmp);
    }

    // cloasing the input file
    input_file.close();

    // opening output file for writing
    ofstream output_file("ice.out");

    if (!output_file.is_open())
    {

        cerr << "Could not open the output file" << endl;

        return EXIT_FAILURE;
    }

    // computing ...
    if (N <= R)
    {
        output_file << 0;
    }
    else if (E == 0)
    {
        output_file << -1;
    }
    else
    {
        output_file << optimal_equip(R, N, E, d_t_r);
    }

    output_file.close();

    return 0;
}
