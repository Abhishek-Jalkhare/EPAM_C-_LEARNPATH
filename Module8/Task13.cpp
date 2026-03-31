//
// Created by AbhishekJalkhare on 27-03-2026.
//
#include <iostream>
#include <algorithm>
#include <ranges>
#include <chrono>
#include <iomanip>
#include <map>
#include <unordered_map>
#include <vector>
using namespace std;

constexpr int NUM_WORDS = 100000;
constexpr int NUM_LOOKUP_TESTS = 10000;
constexpr int NUM_NONEXISTENT_WORDS = 10000;

using WordVector = std::vector<std::string>;
using MilliSeconds = chrono::duration<double, std::milli>;

template <typename Func>
double measureTime(const std::string& description, Func func) {
    const auto start = std::chrono::high_resolution_clock::now();
    func();
    const auto end = std::chrono::high_resolution_clock::now();
    MilliSeconds duration_ms = end - start;
    std::cout << std::fixed << std::setprecision(3);
    std::cout << " " << std::left << std::setw(35) << description + ":" << duration_ms.count() << " ms" << std::endl;
    return duration_ms.count();
}

WordVector generateWords(int count, const std::string& prefix) {
    WordVector words;
    words.reserve(count);
    for (int i = 0; i < count; ++i) {
        words.push_back(prefix + std::to_string(i));
    }
    return words;
}

template <typename MapType>
void conditionallyReserve(MapType& map, size_t count) {
    if constexpr (std::is_same_v<MapType, std::unordered_map<std::string, int>>) {
        // Only call reserve if it's an unordered_map
        map.reserve(count);
        std::cout << " (Reserved " << count << " buckets for unordered_map)" << std::endl;
    }
}

template<typename MapType>
void benchmarkContainer(const std::string& container_name,
    const WordVector& words_to_insert,
    const WordVector& non_existent_words) {
    MapType my_container;
    conditionallyReserve(my_container,words_to_insert.size());
    int i = 0;
    measureTime("Insertion" , [&]() {
        std::ranges::for_each(words_to_insert ,[&](const string& x) {
                 my_container[x]=i++;
        });
    });

    volatile int found_count = 0;
    measureTime("Lookup (Existing Keys)", [&]() {
        for (int j = 0; j < NUM_LOOKUP_TESTS; ++j) { // Using find() is crucial as operator[] would insert if not found
            auto it = my_container.find(words_to_insert[j]);
            if (it != my_container.end()){
                found_count += 1; // Increment to prevent optimization
            }
        }
    });

    // 3. Lookup Time (Non-Existing Keys)
    volatile int not_found_count = 0;
    measureTime("Lookup (Non-Existing Keys)", [&]() {
        for (int j = 0; j < NUM_NONEXISTENT_WORDS; ++j) {
            auto it = my_container.find(non_existent_words[j]);
            if (it == my_container.end()) {
                not_found_count += 1; // Increment to prevent optimization
            }
        }
    });

    cout<<"Size of Container after all insertion's : "<<my_container.size()<<endl;
}

int main(int argc, char* argv[]) {
    cout<<"Welcome a robust benchmarking framework in C++ to empirically compare the \n"
          "performance characteristics (insertion and lookup times) \n"
          "of std::map and std::unordered_map using realistic string data.\n"<<endl;

    // --- Part 1: Data Preparation ---
    std::cout << "Generating " << NUM_WORDS << " unique words..." << std::endl;
    WordVector words_to_insert = generateWords(NUM_WORDS, "word_");
    std::cout << "Generating " << NUM_NONEXISTENT_WORDS << " non-existent words for lookup tests..." << std::endl;
    WordVector non_existent_words = generateWords(NUM_NONEXISTENT_WORDS, "nonexistent_word_");
    std::cout << "Data generation complete.\n" << std::endl;

    // Benchmark std::unordered_map
    benchmarkContainer<std::unordered_map<std::string, int>>("std::unordered_map<std::string, int>", words_to_insert, non_existent_words);

    //Benchamark std::map
    benchmarkContainer<std::map<std::string, int>>("std::map<std::string, int>", words_to_insert, non_existent_words);

    cout<<"std::unordered_map is markedly faster than std::map for bulk insertions and lookups "
          "(both successful and unsuccessful) involving large datasets of strings.";

}