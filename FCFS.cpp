#include<stdio.h>
#include <iostream>
#include <list>
#include<iterator>
using namespace std;
class FCFS{
private:
  list <int> AT_list,BT_list,avg_CT,Timel;
  list <float> P_line;


public:
  FCFS(int sno){
      for (int i = 0; i < sno; i++) {
        int temp;
        cin >> temp;
        AT_list.push_back(temp);
      }
      for (int i = 0; i < sno; i++) {
        int temp;
        cin >> temp;
        BT_list.push_back(temp);
      }
      //showlist(AT_list);
  }
  void CT_calc(){
    int i =0;
    list <int> :: iterator it;
    for(it = AT_list.begin(); it != AT_list.end(); ++it){
        i+=1;
      }
    int temp;
    int tsno = i;
    int AT_array[i+1];
    int BT_array[i];
    float CT_array[i];
    AT_array[tsno]=-1;

    i = 0;
    for(it = AT_list.begin(); it != AT_list.end(); ++it){
        AT_array[i]=*it;
        i++;
    }
    i=0;
    for(it = BT_list.begin(); it != BT_list.end(); ++it){
        BT_array[i]=*it;

        i++;

    }

    temp = Timel.front();

    i = 0;

    Timel.push_front(AT_array[i]);

    while(i<tsno){

    if(Timel.front()<AT_array[i]){

      int temp;
      //cout<<"FIRST LOOP BEFORE TEMP "<<Timel.front()<<"\n";

      Timel.pop_front();
      temp=temp+1;

      Timel.push_front(temp);
      //cout<<"FIRST LOOP "<<Timel.front()<<"\n";

      }

    else if(Timel.front()>=AT_array[i]){
      //cout<<"SECOND LOOP BEFORE TEMP "<<Timel.front()<<"\n";

      int temp;
      temp = Timel.front();
      //Timel.pop_front();
      temp=temp+BT_array[i];
      Timel.push_back(temp);
      //cout<<"Second LOOP "<<Timel.front()<<"\n";
      i+=1;
      }

    }
    cout<<"\n";
//---showlist(Timel); == timeline , process_finish1 ,process_finish2
    Timel.pop_front();
    i=0;
    for(it = Timel.begin(); it != Timel.end(); ++it){
        CT_array[i]=*it;
        i++;
    }

    i=0;
    float to_add = 0;
    for(i=0;i<tsno;i++){
      to_add = to_add+CT_array[i];
    }

    cout<<to_add/tsno;
  }



  void showlist(list <int> g){
    list <int> :: iterator it;
    for(it = g.begin(); it != g.end(); ++it)
        cout<<*it;
    cout << '\n';
  }
};

int main(){
  FCFS obj(2);
  obj.CT_calc();
  return 0;
}
