#include <iostream>
#include <fstream>

using namespace std;

bool check_nr_loaded_rockets(long long satellites[], int N, int K, long long payload)
{
    int nr_rockets = 1;
    long long tmp_payload = 0;
    long long satellite_weight;

    for (int i = 0; i < N; ++i)
    {

        satellite_weight = satellites[i];
        tmp_payload += satellite_weight;

        if (tmp_payload > payload)
        {
            tmp_payload = satellite_weight;
            nr_rockets++;

            if (nr_rockets > K)
            {
                return false;
            }
        }
    }

    return true;
}

long long minimal_payload(long long satellites[], int N, int K)
{
    long long min_max_payload = 0, max_max_payload = 0;

    for (int i = 0; i < N; i++)
    {   
        //computing the maximum weight of a satellite
        if (satellites[i] > min_max_payload)
        {
            min_max_payload = satellites[i];
        }
        max_max_payload += satellites[i];
    }

    long long mid_max_payload;

    while (min_max_payload < max_max_payload)
    {
        mid_max_payload = min_max_payload + (max_max_payload - min_max_payload) / 2;

        if (check_nr_loaded_rockets(satellites, N, K, mid_max_payload))
        {
            max_max_payload = mid_max_payload;
        }
        else
        {
            min_max_payload = mid_max_payload + 1;
        }
    }

    return min_max_payload;
}

int main()
{
    // opening input file for reading
    ifstream input_file("satellites.in");

    if (!input_file.is_open())
    {

        cerr << "Could not open the input file" << endl;

        return EXIT_FAILURE;
    }

    // reading N and K from the input file
    int N, K;

    input_file >> N;
    input_file >> K;

    // reading satellite weights from the input file and storing them
    long long satellite_weight;
    long long satellites[N];

    for (int i = 0; i < N; ++i)
    {
        input_file >> satellite_weight;
        satellites[i] = satellite_weight;
    }

    // opening output file for writing
    ofstream output_file("satellites.out");

    if (!output_file.is_open())
    {

        cerr << "Could not open the output file" << endl;

        return EXIT_FAILURE;
    }

    // computing the minimal  weight for a rocket and writing it in the
    // output file
    output_file << minimal_payload(satellites, N, K);
    
    input_file.close();
    output_file.close();

    return 0;
}
