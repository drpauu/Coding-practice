#include <iostream>
#include <sstream>
#include <string>
#include <vector>

using namespace std;

int comando(string c){
    if(c == "soldat"){
        return 1;
    } else if (c== "sergent"){
        return 2;
    } else if(c == "capita"){
        return 3;
    } else if(c == "coronel"){
        return 4;
    }
    return 0;
}

void inserir_element(pair<string, string> element,
                     vector<pair<string, string>> &v) {
  // Use binary search to find the insertion position
  int left = 0;
  int right = v.size() - 1;
  while (left <= right) {
    int mid = (left + right) / 2;
    if(comando(v[mid].second) == comando(element.second)){
        v.insert(v.begin() + mid-1, element);
        return;
    }
    if (comando(v[mid].second) < comando(element.second)) {
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
  vector<pair<string, string>> sortides;
  // Creem les cues com a vectors buits
  vector<vector<pair<string, string>>> cues(n);

  // Llegim les cues amb els seus clients
  string line;
  getline(cin, line); // Descartem la línia en blanc
  for (int i = 0; i < n; ++i) {
    getline(cin, line);
    istringstream iss(line);
    string client;
    string edat;
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
      string edat;
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