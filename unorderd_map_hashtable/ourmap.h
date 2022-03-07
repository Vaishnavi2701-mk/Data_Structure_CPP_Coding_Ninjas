#include<string>
using namespace std;

template <typename V>

class Mapnode{
public:
string key;    // we will consider our key to be string
V value;       // V type of value
Mapnode* next;

Mapnode(string key, V value){
this->key=key;
this->value=value;
next=NULL;
}

~Mapnode(){
delete next;       // In LL after deleting next whole LL is going to delete
}

};

// Now bucket Array

template <typename V>

class Ourmap{

Mapnode<V>**bucket;      // it will store an address of LL so double pointer

int count;               // keeping count of inserted keys
int numBuckets;

public:
    Ourmap(){
    count=0;
    numBuckets=5;
    bucket=new Mapnode<V>*[numBuckets];        // each bucket contain numBuckets nodes;

    for(int i=0;i<numBuckets;i++){
        bucket[i]=NULL;                   // initialize every node with Null
    }
    }

    ~Ourmap(){
    for(int i=0;i<numBuckets;i++){
        delete bucket[i];
    }
    delete [] bucket;
    }

// functions
//1) No of keys

int size(){
return count;
}

//2) insert

// but insert is depend on getBucketIndex
// it is hashfuction
private:
    int getBucketIndex(string key){
       int hashCode=0;
       int baseCoeff=1;

       //"abc" =a*p^2+b*p^1+c*p^0
       // p^0 = 1
       // taking p any prime no

       for(int i=key.length()-1;i>0;i--){
        hashCode+=key[i]*baseCoeff;
        //compress hashCode
        hashCode=hashCode%numBuckets;
        //imagine in case of power
        baseCoeff=baseCoeff*37;
        //compress baseCoefficient
        baseCoeff=baseCoeff%numBuckets;
       }
       return hashCode% baseCoeff;
    }

    void rehash(){
    Mapnode<V>**temp=bucket;
    bucket=new Mapnode<V>*[2*numBuckets];

    // initialize NULL in new Bucket
    for(int i=0;i<2*numBuckets;i++){
        bucket[i]=NULL;
    }
    int oldBucketCount=numBuckets;
    numBuckets*=2;
    count=0;
    // copy everything int new bucket
    for(int i=0;i<oldBucketCount;i++){
        Mapnode<V>*head=temp[i];
        while(head!=NULL){
            string key=head->key;
            V value=head->value;
            insert(key,value);
            head=head->next;
        }
    }
    // to delete old temp;
    for(int i=0;i<oldBucketCount;i++){
        Mapnode<V>*head=temp[i];
        delete head;
    }
      delete [] temp;
    }
public:

    void insert(string key, V value){
    int bucketIndex=getBucketIndex(key);

    Mapnode<V>* head=bucket[bucketIndex];
    while(head!=NULL){
        //search if key is already present
        if(head->key==key){
            // if present already then only update value
            head->value=value;
            return;
        }
        head=head->next;
    }
    // otherwise back to ur head and insert new node as hey-value pair
    head=bucket[bucketIndex];
    Mapnode<V>*node=new Mapnode<V>(key,value);
    node->next=head;
    bucket[bucketIndex]=node;
    count++;   //as we insert new node increase count;
    double loadFactor=(1.0*count)/numBuckets;
    if(loadFactor>0.7){
        rehash();
    }
    }

    double getloadFactor(){
     double loadFactor=(1.0*count)/numBuckets;
     return loadFactor;
    }
    // 3) remove

    void remove(string key){
       int bucketIndex=getBucketIndex(key);
        Mapnode<V>* head=bucket[bucketIndex];
        Mapnode<V>* prev=NULL;

        while(head!=NULL){
          if(head->key==key){
            // if we have to delete a key which present at head at first that time prev is NULL
            // then we cant put prev->next=head->next;
            if(prev==NULL){
            bucket[bucketIndex]=head->next;
            }
            else{
             prev->next=head->next;
            }
            V value=head->value;
            head->next=NULL;
            delete head;
            count--;
            cout<<value;
          }
          prev=head;
          head=head->next;

        }
       return ;          // that means the key which we looking for is not present
    }

    // 4) search
    V getValue(string key){
          int bucketIndex=getBucketIndex(key);
          Mapnode<V>* head=bucket[bucketIndex];

          while(head!=NULL){
            if(head->key==key){
                return head->value;
            }
            head=head->next;
          }
        return 0;
    }

};
