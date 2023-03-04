#include <iostream>
#include <sstream>
#include <string>
#include <vector>

using namespace std;

void inserir_element(pair<string, float> element,
                     vector<pair<string, float>> &v) {
  // Trobem la posició on s'ha d'inserir l'element
  int esq = 0;
  int dre = v.size() - 1;
  while (esq <= dre) {
    int mig = (esq + dre) / 2;
    if (v[mig].second < element.second) {
      esq = mig + 1;
    } else {
      dre = mig - 1;
    }
  }
  // Inserim l'element a la posició trobada
  v.insert(v.begin() + esq, element);
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
      inserir_element({client, edat}, cues[i]);
    }
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
    cout << "cua " << i + 1 << ": ";
    for (int j = cues[i].size() - 1; j >= 0; --j) {
      cout << cues[i][j].first << " ";
    }
    cout << endl;
  }

  return 0;
}
