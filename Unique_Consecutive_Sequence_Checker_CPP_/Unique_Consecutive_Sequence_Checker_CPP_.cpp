#include <iostream>
#include <vector>
#include <algorithm>
#include <unordered_set>

bool isCoolSequence(std::vector<int>& sequence, int k) {
    sort(sequence.begin(), sequence.end()); // Rearanjam in numere consecutive
    
    // unordered_set nu poate contine elemente duplicate
    std::unordered_set<int> unique_elements(sequence.begin(), sequence.end());
    if (unique_elements.size() != k) {
        //std::cout << "    DEBUG | false 01";
        return false;
    }
    for (int i = 0; i < sequence.size() - 1; ++i) {
        if (sequence[i + 1] - sequence[i] != 1) {
            //std::cout << "    DEBUG | false 02";
            return false;
        }
    }
    return true;
}

int main() {
    int N, K;
    std::cout << "Introdu numarul maxim al sirului: ";
    std::cin >> N;
    std::cout << "Introdu numarul de verificare al sirului: ";
    std::cin >> K;
    std::cout << std::endl;


    std::cout << "Introdu numerele: " << std::endl;
    std::vector<int> A(N);
    for (int i = 0; i < N; ++i) {
        std::cout << "Numarul " << i + 1 << " este: ";
        std::cin >> A[i];
        std::cout << std::endl;
    }

    // begin() este un iterator catre primul element din vector
    std::vector<int> subsequence(A.begin(), A.begin() + K);

    if (isCoolSequence(subsequence, K)) {
        int max_value = *max_element(subsequence.begin(), subsequence.end());
        std::cout << "Secventa ";
        for (int i = 0; i < K; ++i) {
            std::cout << subsequence[i] << " ";
        }
        std::cout << "este cool." << std::endl;
        std::cout << "Valoarea maxima din secventa este: " << max_value << std::endl;

    }
    else {
        std::unordered_set<int> unique_elements(A.begin(), A.end());
        std::cout << unique_elements.size() << std::endl;
    }

    return 0;
}
