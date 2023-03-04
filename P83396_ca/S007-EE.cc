#include <iostream>
#include <sstream>
#include <string>
#include <vector>

using namespace std;

void quicksort(std::vector<std::pair<std::string, float>> &v, int left,
               int right) {
  // base case: if the left index is greater than or equal to the right index,
  // we're done
  if (left >= right) {
    return;
  }

  // choose a pivot element
  int pivotIndex = (left + right) / 2;
  std::pair<std::string, float> pivot = v[pivotIndex];

  // partition the vector
  int i = left;
  int j = right;
  while (i <= j) {
    while (v[i].second < pivot.second) {
      i++;
    }
    while (v[j].second > pivot.second) {
      j--;
    }
    if (i <= j) {
      std::swap(v[i], v[j]);
      i++;
      j--;
    }
  }

  // recursive calls to quicksort on the left and right partitions
  quicksort(v, left, j);
  quicksort(v, i, right);
}

void inserir_element(pair<string, float> element,
                     vector<pair<string, float>> &v) {
  // Use binary search to find the insertion position
  int left = 0;
  int right = v.size() - 1;
  while (left <= right) {
    int mid = (left + right) / 2;
    if (v[mid].second < element.second) {
      left = mid + 1;
    } else {
      right = mid - 1;
    }
  }

  // Insert the element at the desired position
  v.insert(v.begin() + left, element);
}

int main() {
  // Llegim el nombre de cues
  int n;
  cin >> n;
  vector<pair<string, float>> sortides;
  // Creem les cues com a vectors buits
  vector<vector<pair<string, float>>> cues(n);

  // Llegim les cues amb els seus clients
  string line;
  getline(cin, line); // Descartem la línia en blanc
  for (int i = 0; i < n; ++i) {
    getline(cin, line);
    istringstream iss(line);
    string client;
    float edat;
    while (iss >> client >> edat) {
      cues[i].push_back({client, edat});
    }
    quicksort(cues[i], 0, cues[i].size() - 1);
  }

  // Llegim els successos
  string successos;
  while (getline(cin, successos)) {
    istringstream iss(successos);
    string accio;
    iss >> accio;
    if (accio == "ENTRA") {
      string client;
      float edat;
      int cua;
      iss >> client >> edat >> cua;
      inserir_element({client, edat}, cues[cua - 1]);
    } else if (accio == "SURT") {
      int cua;
      iss >> cua;
      if (!cues[cua - 1].empty()) {
        unsigned int s = cues[cua - 1].size() - 1;
        sortides.push_back(cues[cua - 1][s]);
        cues[cua - 1].erase(cues[cua - 1].end());
      }
    }
  }
  unsigned int i = 0;
  cout << "SORTIDES" << endl;
  cout << "--------" << endl;
  while (i < sortides.size()) {
    cout << sortides[i].first << endl;
    i++;
  }
  cout << endl;
  cout << "CONTINGUTS FINALS" << endl;
  cout << "-----------------" << endl;
  // Imprimim les cues
  for (int i = 0; i < cues.size(); ++i) {
    cout << "cua " << i + 1 << ":";
    for (int j = cues[i].size() - 1; j >= 0; --j) {
      cout << " " << cues[i][j].first;
    }
    cout << endl;
  }

  return 0;
}

/*
ALGORISME DE QUICKSORT FET EN UN VECTOR

// Funció de partició per al quicksort
int particio(vector<int>& v, int esq, int dre) {
  // Triem el pivot com el darrer element del vector
  int pivot = v[dre];
  // Inicialitzem l'índex del primer element més gran que el pivot
  int i = esq - 1;
  // Partim el vector en dos subvectors
  for (int j = esq; j < dre; ++j) {
    if (v[j] <= pivot) {
      ++i;
      swap(v[i], v[j]);
    }
  }
  // Intercanviem el pivot amb el primer element més gran que ell
  swap(v[i+1], v[dre]);
  // Retornem l'índex del pivot
  return i + 1;
}

// Funció de quicksort
void quicksort(vector<int>& v, int esq, int dre) {
  if (esq < dre) {
    // Partim el vector i ordenem els subvectors
    int pivot = particio(v, esq, dre);
    quicksort(v, esq, pivot - 1);
    quicksort(v, pivot + 1, dre);
  }
}
*/
