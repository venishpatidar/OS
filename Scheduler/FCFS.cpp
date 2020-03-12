#include<stdio.h>
#include <iostream>
#include <list>
#include"algorithm"
#include<iterator>
using namespace std;
class Scheduler{
private:
  list <int> AT_list,BT_list,Timel,CT_list;
  float avg_CT;
  list <float> P_line;
  int tsno;//universal serial number


public:
  Scheduler(int sno){
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

  void FCFS_CALC(){
    int i =0;
    list <int> :: iterator it;
    for(it = AT_list.begin(); it != AT_list.end(); ++it){
        i+=1;
      }
    int temp;
    tsno = i;
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
    
    i = 0;

    Timel.push_front(AT_array[i]);

    while(i<tsno){

    if(Timel.front()<AT_array[i]){

      //cout<<"FIRST LOOP BEFORE TEMP "<<Timel.front()<<"\n";
      temp = Timel.front();
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
        CT_list.push_back(CT_array[i]);
        i++;
    }
    i=0;
    float to_add = 0;
    for(i=0;i<tsno;i++){
      to_add = to_add+CT_array[i];
    }
    avg_CT=to_add/tsno;
    system("clear");
    cout<<"Calculating through First come First Serve solution\n";
    
  }

  void SJF_CALC(){
    int i =0;
    list <int> :: iterator it;
    for(it = AT_list.begin(); it != AT_list.end(); ++it){
        i+=1;
      }
    int temp;
    tsno = i;
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
    
    i = 0;

    Timel.push_front(AT_array[i]);

    while(i<tsno){

    if(Timel.front()<AT_array[i]){

      temp = Timel.front();
      Timel.pop_front();
      temp=temp+1;

      Timel.push_front(temp);

      }

    else if(Timel.front()>=AT_array[i]){
      int temp2;
      temp2 = Timel.front();
      if(temp2>=tsno){
        temp2=tsno;
      }
      auto min_value=min_element(BT_array,BT_array+temp2);
      temp = *min_value;
      //showarray(BT_array,tsno);
      //cout<<"min val = "<<temp<<" index = "<<temp2<<" val = "<<BT_array[temp2] <<"\n";
      auto rep_index = find(BT_array,BT_array+tsno,temp);
      *rep_index = 1000*(i+1);
      temp = temp+Timel.front();
      Timel.pop_front();
      Timel.push_front(temp);
      

      Timel.push_back(temp);
      i+=1;
      }

    }
    showarray(BT_array,tsno);
    cout<<"\n";
    Timel.pop_front();
    rearange(BT_array,Timel,tsno);


    i=0;
    for(it = Timel.begin(); it != Timel.end(); ++it){
        CT_array[i]=*it;
        CT_list.push_back(CT_array[i]);
        i++;
    }
    i=0;
    float to_add = 0;
    for(i=0;i<tsno;i++){
      to_add = to_add+CT_array[i];
    }
    avg_CT=to_add/tsno;
    system("clear");
    cout<<"Calculating through Shortest Job First solution\n";
    
  }

  void LJF_CALC(){
    int i =0;
    list <int> :: iterator it;
    for(it = AT_list.begin(); it != AT_list.end(); ++it){
        i+=1;
      }
    int temp;
    tsno = i;
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
    
    i = 0;

    Timel.push_front(AT_array[i]);

    while(i<tsno){

    if(Timel.front()<AT_array[i]){

      temp = Timel.front();
      Timel.pop_front();
      temp=temp+1;

      Timel.push_front(temp);

      }

    else if(Timel.front()>=AT_array[i]){
      int temp2;
      temp2 = Timel.front();
      if(temp2>=tsno){
        temp2=tsno;
      }
      auto min_value=max_element(BT_array,BT_array+temp2);
      temp = *min_value;
      //showarray(BT_array,tsno);
      //cout<<"min val = "<<temp<<" index = "<<temp2<<" val = "<<BT_array[temp2] <<"\n";
      auto rep_index = find(BT_array,BT_array+tsno,temp);
      *rep_index = 1000*(i+1);
      temp = temp+Timel.front();
      Timel.pop_front();
      Timel.push_front(temp);
      

      Timel.push_back(temp);
      i+=1;
      }

    }
    showarray(BT_array,tsno);
    cout<<"\n";
    Timel.pop_front();
    rearange(BT_array,Timel,tsno);


    i=0;
    for(it = Timel.begin(); it != Timel.end(); ++it){
        CT_array[i]=*it;
        CT_list.push_back(CT_array[i]);
        i++;
    }
    i=0;
    float to_add = 0;
    for(i=0;i<tsno;i++){
      to_add = to_add+CT_array[i];
    }
    avg_CT=to_add/tsno;
    system("clear");
    cout<<"Calculating through Shortest Job First solution\n";
    
  }
  
  void displaytable(){
    
    list <int> :: iterator it;
    int temp_row[3];
    cout<<"\tAT\tBT\tCT\n";
    for(int i=0;i<tsno;i++){
      it = AT_list.begin();
      advance(it,i);
      temp_row[0] = *it;
      it = BT_list.begin();
      advance(it,i);
      temp_row[1] = *it;
      it = CT_list.begin();
      advance(it,i);
      temp_row[2] = *it;
      cout<<"\t";
      showarray(temp_row,3);
    }
    cout<<"average:\t\t"<<avg_CT<<endl;
  }

  void showarray(int array[],int size){
    for(int i=0;i<size;i++){
      cout<<array[i]<<"\t";
    }
    cout<<"\n";
  }

  void showlist(list <int> g){
    list <int> :: iterator it;
    for(it = g.begin(); it != g.end(); ++it)
        cout<<*it<<" ";
    cout << '\n';
  }

  void rearange(int array[],list <int>l,int max){
    list <int> :: iterator main_it,temp_it;
    list <int> temp_list = l;
    int temp_val;
    for(int i=0;i< max;i++){
      temp_val = array[i]/1000;
      temp_it = temp_list.begin();
      main_it = l.begin();
      advance(temp_it,(temp_val-1));
      advance(main_it,i);
      *main_it=*temp_it; 
    }
    Timel=l;
  }

};

int main(){
  cout<<"How many process?"<<endl;
  int hm_process;
  cin >> hm_process; 
  cout<<"Enter all Arival time first than brust time."<<endl;
  Scheduler obj(hm_process);
  obj.SJF_CALC();
  cout<<"\n\n";
  obj.displaytable();
  return 0;
}
