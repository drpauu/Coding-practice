#include <iostream>

using namespace std;
struct Temps {
  int hora, minut, segon;
} tiempo, t1, t2;

void un_segon(const Temps &t, Temps &t1, Temps &t2) {
  int s, m, h;
  s = t.segon;
  m = t.minut;
  h = t.hora;
  if (s == 59) {
    if (m == 59) {
      if (h == 23) {
        cout << "0 0 0" << endl;
      } else {
        cout << h + 1 << " 0"
             << " 0" << endl;
      }
    } else {
      cout << t.hora << " " << m + 1 << " 0" << endl;
    }
  } else {
    cout << t.hora << " " << t.minut << " " << s + 1 << endl;
  }
  if (s == 0) {
    if (m == 0) {
      if (h == 0) {
        cout << "23 59 59" << endl;
      } else {
        cout << h - 1 << " 59 "
             << "59" << endl;
      }
    } else {
      cout << t.hora << " " << m - 1 << "59" << endl;
    }
  } else {
    cout << t.hora << " " << t.minut << " " << s - 1 << endl;
  }
}

int main() {
  while (cin >> tiempo.hora >> tiempo.minut >> tiempo.segon) {
    t1 = tiempo;
    t2 = tiempo;
    un_segon(tiempo, t1, t2);
  }
}
