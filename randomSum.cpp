#include <iostream>
#include <chrono>
#include <unistd.h>
#include <vector>

int
main (int ac, char *av[])
{
    int sleep_secs = 2; // default sleep for 2 secs

    // if (ac > 1)  // if user entered a value after the prog name, parse it
    //     sleep_secs = std::atoi(av[1]);
    int64_t input;

    if (ac > 1)  // if user entered a value after the prog name, parse it
        input = std::atoi(av[1]);

    std::cout << "input" << input << std::endl;

    std::vector<int64_t> numbers(input);    
    // int64_t numbers[input];
    int64_t inputCopy = input;
    int64_t sum = 0;

    int64_t i;    
    for(i=1; i<=input; i++){
        numbers[i-1] = lrand48() % input;
    }    
    std::cout << "Going to sleep for " << sleep_secs << " seconds " << std::endl;

    std::chrono::time_point<std::chrono::high_resolution_clock> start_time = std::chrono::high_resolution_clock::now();

    sleep(sleep_secs);

    int64_t j;
    int64_t k = 0;
    for(j=0; j<input; j++){
        sum += numbers.at(k);
        k = numbers.at(k);
    }

    std::cout << "input" << input << std::endl;
    std::cout << "sum" << sum << std::endl;

    std::chrono::time_point<std::chrono::high_resolution_clock> end_time = std::chrono::high_resolution_clock::now();

    std::chrono::duration<double> elapsed = end_time - start_time;

    std::cout << " Elapsed time is : " << elapsed.count() << " " << std::endl;
    return 1;
}