#include <stdio.h>
#include <vector>
#include <list>
#include <math.h>
float EPS = 4.0f;

using namespace std;

class newron;
class synaps;

class newron {
public:
  list<synaps*> next;
  list<synaps*> prev;
  float o;
  float X;

  float fx(float x) {
    o = exp(-EPS*x);
    return o;
  }
};

class synaps {
public:
  newron* next;
  newron* prev;
  float w;

  synaps() {
    next = prev = NULL;
  }

  float wx(float x) {
    return w*x;
  }
};

class network {
public:
  list< list<newron*> > layer;
  list<newron*> out;

  float run(list<newron*> &input) {
    for(list< list<newron *> >::iterator i = layer.begin(); i != layer.end(); i++) {
      for(list<newron *>::iterator j = i->begin(); j != i->end(); j++) {
        (*j)->o;
        for(list<synaps *>::iterator k = ((*j)->next).begin(); k != ((*j)->next).end(); k++) {
          newron* next = (*k)->next;
        }
      }
    }
  }
};

void input_data(network& net) {
}

int main(void) {
  network* newral_net = new network();
  input_data(*newral_net);
  return 0;
}
