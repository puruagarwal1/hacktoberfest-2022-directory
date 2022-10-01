*
STL: Standard Template Library
1.Containers
2.Iterators
3.Algorithms
4.Functors

1.Containers
    Sequintial
        -vectors
        -stack
        -queue
        -pair(not a container)
    Ordered(data stored in ordered way)
        -maps
        -multimaps
        -set
        -multiset
    Unordered
        -unordered map
        -unordered set

    *Nested Containers
2.Iterators(similar to pointers)
    -point to memory address of containers
    -.begin(),.end()
    -vector<int>::interator it; (declaration)
3.Algorithms
    -upper bound
    -lower bound
    -sort(comparator)
    -max_element
    -min_element
    -accumulate(array ka sum)
    -reverse
    -count
    -find
    -next permutations
    -prev permutations
4.Functors (classes which can act as functions)


*/

*
CONTAINERS
1)Pairs and Vectors
    Pair- class in c++
          stores two data types/containers
          maintains a relation between the two data types/containers

          int main(){
            pair<int,string>p;
            pair<3,7>pr;
            //taking input in pair
            pair<int,int>p1;
            p1={3,4}; //or p1=make_pair(3,4);
            pair<string,double>pt;
            cin>>p1.first>>pt.second;
            pair<string,double>pts=pt;
            pts.first="hemlo";//this wont change the value in the pair pt because it passed by value, but if use 
                              // &pts=pt , this will change the value in pt correspondingly since it is changed by reference
            //explaining the relation maintainence of pair
            int a[]={1,2,3,4};
            int b[]={2,3,4,5};
            pair<int,int>p_array[4];
            p_array[0]={1,2};
            p_array[1]={2,3};
            p_array[2]={3,4};
            p_array[3]={4,5};
            for(int i=0;i<4;i++){
                cout<<p_array[i].first<<" "<<p_array[i].second<<endl;
            }
            //now if we use any operation on p_array[], it will correspondingly reflect after we print it. eg, we can use swap(p_array[0],p_array[3]) function
          //another example
          int n;
          cin>>n;
          int a[n],b[n];
          for(int i=0;i<n;i++){cin>>a[i];}
          for(int i=0;i<n;i++){cin>>b[i];}
          pair<int,int>pary[n];
          for(int i=0;i<n;i++){pary[i]={a[i],b[i]};}
          for(int i=0;i<n;i++){cout<<pary[i].first<<" "<<pary[i].second<<endl;}

    Vectors- continuous memory blocks
             dynamic arrays
             initial size after declaration is 0
             declared using the syntax
                vector<data_type/container>v;

            input in vector
                vector<int>v;
                int n;
                cin>>n;
                for(int i=0;i<n;i++){
                    int x;
                    cin>>x;
                    v.pushback(x);
                }
                //v.size() gives the size of the current vector
                for(int i=0;i<v.size();i++){
                    cout<<v[i]<<" ";
                }

            decleration and initialization
                vector<int>v1(10);//creates a vector of size 10 and all elements as 0
                vector<int>v2(10,4);//creates a vector of size 10 and all elements as 4
                v1.push_back(7);//adds an 11th element 7 at the end of the vector

            removing a element of a vector
                vector<int>v;
                v.push_back(4);
                v.push_back(7);
                // the vector has two elements , 4 7
                v.pop_back();//this removes the last element i.e. 7

            copying of vectors
                very simple and can be done directly using the syntax
                vector<int>v1;
                v1.push_back(9);
                v1.push_back(0);
                vector<int>v2=v1;// due to this, any change in v1 does not affect v2; while in arrays, pointers are copied , so any change is reflected in both the arrays
                //above operation is O(n) operation
                v2.push_back(2);
                //printing the vectors
                for(int i=0;i<v1.size();i++)
                {cout<<v1[i]<<" ";}//prints 9 0
                for(int i=0;i<v2.size();i++)
                {cout<<v2[i]<<" ";}//prints 9 0 2

            while making a function, that wants to change the passed vector, use reference of the vector because if one creates a copy, it will only happen in the function and not reflect in actual vector
                example,
                #include <bits/stdc++.h>
                #define pb push_back
                using namespace std;
                int printVref(vector<int>&v){
                    cout<<"size: "<<v.size()<<endl;
                    for(int i=0;i<v.size();i++){
                        cout<<v[i]<<" ";
                    }
                    v.pb(99);
                    cout<<endl;
                    return 0;
                }
                int printVcopy(vector<int>v){
                    cout<<"size: "<<v.size()<<endl;
                    for(int i=0;i<v.size();i++){
                        cout<<v[i]<<" ";
                    }
                    v.pb(99);
                    cout<<endl;
                    return 0;
                }
                int main(){
                    vector<int>v;
                    vector<int>vec;
                    v.pb(3);
                    v.pb(5);
                    vec.pb(3);
                    vec.pb(5);
                    printVref(v);//size: 2 and prints 3 5
                    printVref(v);//size: 3 and prints 3 5 99
                    printVcopy(vec);//size: 2 and prints 3 5
                    printVcopy(vec);//size: 2 and prints 3 5 again, because here a copy of the vector was created int function and the changes were made in that copy
                }

    Nesting in vectors-
        #Vector of Pair-
            initialize and declare
                vector<pair<int,int>>v={{2,5},{6,4},{7,7}};
            for taking input
                vector<pair<int,int>>v;
                int x,y,n;
                cin>>n;
                for(int i=0;i<n;i++){
                    cin>>x>>y;
                    v.push_back({x,y});//or v.push_back(make_pair(x,y));
                }
            for printing(here each element of the vector is a pair)
                void vprt(vector<pair<int,int>>&v){
                    cout<<"Size: "<<v.size()<<endl;
                    for(int i=0;i<v.size();i++){
                        // here, v[i] has a pair stored in it, so in short, we need to print a pair
                        cout<<v[i].first<<" "<<v[i].second;
                    }
                    cout<<endl;
                }
                int main(){
                    vector<pair<int,int>>v;
                    int x,y,n;
                    cin>>n;
                    for(int i=0;i<n;i++){
                        cin>>x>>y;
                        v.push_back({x,y});//or v.push_back(make_pair(x,y));
                    }
                    vprt(v);
                    return 0;
                }

        #Array of Vectors-(like 2d array, but here no of rows is constant)
            declaring an array of vectors
                vector<int>v[10];// creates an array of 10 vectors, where, the elements (v[0],v[1],v[2],..,v[9]) are vectors of initial size 0
            initialize
                .
            taking input and printing
                void prtv(vector<int>&v){
                    cout<<"Size: "<<v.size()<<endl;
                    for(int i=0;i<v.size();i++){
                        //each element of the array is a vector, so will print a vector
                        cout<<v[i]<<" ";
                    }
                    cout<<endl;
                }
                int main(){
                    int arr_size;
                    cin>>arr_size;
                    vector<int>a[arr_size];
                    // below for loop for taking input in an array
                    for(int i=0;i<arr_size;i++){
                        int vec_size;
                        cin>>vec_size;
                        // here, the below for loop is for taking input in the i th vector element
                        for(int j=0;j<vec_size;j++){
                            //i th element is a vector, so we have to push back the value in the i th element
                            int v_ipt;
                            cin>>v_ipt;
                            v[i].push_back(v_ipt);
                        }
                    }
                    //printing the elements of the array
                    for(int i=0;i<arr_size;i++){
                        prtv(v[i]);
                    }
                    return 0;
                }

        #Vector of Vectors-(like a 2d array, but no of rows and columns can change dynamically)
            initialize
                vector<vector<int>>v;
            input and printing
                #include <bits/stdc++.h>
                using namespace std;
                void prtv(vector<int>&v){
                    cout<<"Size: "<<v.size()<<endl;
                    for(int i=0;i<v.size();i++){
                        //each element of the vector is a vector, so will print a vector
                        cout<<v[i]<<" ";
                    }
                    cout<<endl;
                }
                int main(){
                    vector<vector<int>>v;
                    int row;
                    cin>>row;
                    for(int i=0;i<row;i++){
                        int col;
                        cin>>col;
                        // for pushing back values, first we need some vector which is initialised
                        vector<int>temp;
                        for(int i=0;i<col;i++){
                            int x;
                            cin>>x;
                            temp.push_back(x);
                        }
                        v.push_back(temp);
                    }
                    for(int i=0;i<v.size();i++){
                        prtv(v[i]);
                    }
                    cout<<endl;
                    cout<<v[0][1];
                    // while printing, take v[0] as a complete vector,[1] in front of it resembles the 2nd element
                    return 0;
                }
                OR
                #include <bits/stdc++.h>
                using namespace std;
                void prtv(vector<int>&v){
                    cout<<"Size: "<<v.size()<<endl;
                    for(int i=0;i<v.size();i++){
                        //each element of the vector is a vector, so will print a vector
                        cout<<v[i]<<" ";
                    }
                    cout<<endl;
                }
                int main(){
                    vector<vector<int>>v;
                    int row;
                    cin>>row;
                    for(int i=0;i<row;i++){
                        int col;
                        cin>>col;
                        //here we can also pass an empty vector as an i th row initialising vector
                        v.push_back(vector<int>());
                        for(int i=0;i<col;i++){
                            int x;
                            cin>>x;
                            v[i].push_back(x);
                        }
                    }
                    for(int i=0;i<v.size();i++){
                        prtv(v[i]);
                    }
                    cout<<endl;
                    cout<<v[0][1];
                    // while printing, take v[0] as a complete vector,[1] in front of it resembles the 2nd element
                    return 0;
                }

2)Maps
    Maps-stores key and it's value i.e. they store a pair
        -initialize and input
            map<int,string>m;
            m[1]="abc";
            m[4]="def";
            m[2]="ghi";
            // or
            m.insert({6,"jkl"});
        -using iterators to access the elements
            #include <bits/stdc++.h>
            using namespace std;
            int main(){
                map<int,string>m;
                m[4]="tr";
                m[1]="rtf";
                m[2]="art";
                m.insert({6,"ilit"});
                //using the auto key word for iterator
                for(auto it=m.begin();it!=m.end();it++){
                    //map stores a pair
                    cout<<(*it).first<<" "<<(*it).second<<endl;
                }
                return 0;
            }
        -if key is stored, but no value is stored, by default 0 is stored
        -map always stores in a sorted way(increasing order for int as key and lexographically for string as key)
        -the keys are unique, if the same key is used, the value is updated
            m[1]="asdfgh";
            m[2]="a";
            m[2]="beluga"; //now, the value is updated to 'beluga' from 'a'
        -some functions of maps
            .find()
                -returns the value of the iterator if the key is present else returns the .end() operator
                -eg,
                    map<int,string>m;
                    int n;
                    cin>>n;
                    for(int i=1;i<=n;i++){
                        cin>>m[i];
                    }
                    int t;
                    cin>>t;
                    auto it=m.find(t);
                    if(it==m.end()){cout<<"no value";}
                    else{cout<<(*it).first<<" "<<(*it).second<<endl;}
            .erase()
                -erases the value
                -can take both key and iterator as input
                -eg,
                    #include <bits/stdc++.h>
                    using namespace std;
                    void mpr(map<int,string>&m){
                        cout<<m.size()<<endl;
                        for(auto it=m.begin();it!=m.end();it++){
                            cout<<(*it).first<<" "<<(*it).second<<endl;
                        }
                    }
                    int main(){
                        map<int,string>m;
                        int n;
                        cin>>n;
                        for(int i=1;i<=n;i++){
                            cin>>m[i];
                        }
                        int t,y;
                        cin>>t>>y;
                        m.erase(t);
                        auto it=m.find(y);
                        m.erase(it);
                        if(it!=m.end())
                            // cout<<(*it).first<<" "<<(*it).second<<endl;
                            mpr(m);
                        return 0;
                    }
            .clear()
                -deletes all elements of the map (rather all STL containers)
        -an example,
        Given N strings, print unique strings in lexicographically order with their frequency
        N<=10^5 and |S|<=100
        #include<bits/stdc++.h>
        using namespace std;
        void mpr(map<string,int>&m){
            cout<<m.size()<<endl;
            for(auto it=m.begin();it!=m.end();it++){
                cout<<(*it).first<<" "<<(*it).second<<endl;
            }
        }
        int main(){
            int n;
            string s;
            cin>>n;
            //maps are useful because they store in sorted way
            map<string,int>m;
            for(int i=1;i<=n;i++){
                //take a string as an input
                cin>>s;
                //the default value of the key stored is 0
                //all the repeated keys will get the corresponding updated value
                m[s]+=1;
            }
            mpr(m);
            return 0;
        }
    Unordered maps-(a bit faster than simple maps)
        -similar to maps i.e., has same functions, but differ in time complexity,inbuit implementation (based on hash table), valid keys datatype
        -decalration and initialisation
            unordered_map<int,string>m;
            m[1]="asdfg";
            m[4]="drtgb";
            m[2]="jfudh";
        -complex data types can't be used (only simple data types like, int, float, double,char, long, long long,....,string)
        -if sequence of output doesn't matter, then use unordered maps
            #include<bits/stdc++.h>
            using namespace std;
            int main(){
                unordered_map<string,int>m;
                int t;string s;
                cin>>t;
                while(t--){
                    cin>>s;
                    m[s]++;
                }
                for(auto it=m.begin();it!=m.end();it++){
                    cout<<(*it).first<<" "<<(*it).second<<endl;
                }
                return 0;
            }
    Multimaps-(little bkc)
        -same key value hone ke baad bhi woh value store ho jati hai

3)Sets
    Sets-similar to maps, but sets just store the keys
        -simply a collection of elements
        -stores uniques elements in sorted order
        -internal implementation is "red-black trees", handle insertions in log(n) time complexity
        -initialising and input
            set<data_type/container>s;
            s.insert("hemlo");
            s.insert("beluwuga");
        -s[2], like operator dosen't exist in set, we need to use .find() function
        -.find() function takes the value of the element and returns the value of its iterator, if the element exists
         and if the element doesn't exist, then we get .end() iterator
            set<string>s;
            int n;
            cin>>n;
            for(int i=1;i<=n;i++){
                string str;
                cin>>str;
                s.insert(str);
            }
            string t;
            cin>>t;
            auto it=s.find(t);
            if(it==s.end()){
                // we need this condition else the compiler will throw an error (segmentation fault)
                cout<<"not present in the set"<<endl;
            }
            else{
                cout<<(*it)<<",is present in the set"<<endl;
            }
        -printing the set
            //let us implement a print function
            void set_print(set<string>&s){
                for(auto value:s){
                    cout<<value<<endl;
                }
                //or
                for(auto it=s.begin();it!=s.end();it++){
                    cout<<(*it)<<endl;
                }
            }
        -removing an element, use .erase() function, it can take both value as well as iterator as input
            s.erase("beluga");
            //or
            auto it=s.find("raze");
            s.erase(it);
        -example,
            Given n strings, print strings in lexicographical order
                #include <bits/stdc++.h>
                using namespace std;
                void print_set(set<string>&s){
                    for(auto val:s){
                        cout<<val<<endl;
                    }
                }
                int main(){
                    set<string>s;
                    int n;
                    cin>>n;
                    while(n--){
                        string st;
                        cin>>st;
                        s.insert(st);
                    }
                    cout<<endl;
                    print_set(s);
                    return 0;
                }
    Unordered sets-
        -very similar to ordered sets
        -others functions are also same
        -but the data type must be simple
        -the internal implementation is "hash table", it deals with insertions of time complexity of o(1)
        -initialisation
            unordered_set<data_type>s;
        -example,
            Given n srings and q queries, in each query you are 
            given a string. print yes if present, else print no.
                //we can even use ordered sets, but then it will be of higher time complexity
                #include <bits/stdc++.h>
                using namespace std;
                int main(){
                    unordered_set<string>s;
                    int n;
                    cin>>n;
                    while(n--){
                        string st;
                        cin>>st;
                        s.insert(st);
                    }
                    int q;
                    cin>>q;
                    while(q--){
                        string str;
                        cin>>str;
                        auto it=s.find(str);
                        if(it!=s.end()){
                            cout<<"Yes"<<endl;
                        }
                        else{
                            cout<<"No"<<endl;
                        }
                    }
                    return 0;
                }
    Multisets
        -allows same key to be stored in the set (similar to ordered sets)
        -mostly log(n) operations
        -initialisation
            multiset<data_type>s;
        -.find() function
            if multiple values are present, then it returns the iterator of the first element
        -.erase() function
            we can pass both value as well as the iterator, but, if we pass directly the value, then all those values will get deleted,
            but if one passes an iterator of the repeated element, the first (and only one) element will get deleted
            eg
              multiset<int>s;
              s.insert(1);
              s.insert(2);
              s.insert(3);
              s.insert(1);
              auto it=s.find(1);
              if(it!=s,end()){
                 s.erase(it);
              }// erases just the first 1
              // s.erase(1); erases both the 1
        -.clear()

        -one question from hackerearth
        #include <bits/stdc++.h>
        #define ll long long
        using namespace std;
        int main(){
            ll t;
            cin>>t;
            while(t--){
                multiset<long long int>s;
                ll n,k;
                cin>>n;
                cin>>k;
                ll a;
                for(int i=0;i<n;i++){
                    cin>>a;
                    s.insert(a);
                }
                auto it=s.end();
                s.end()--;//or auto it=--s.end();
                ll sum=(*it);
                while(k--){
                    s.erase(*it);
                    s.insert((*it)/2);
                    sum=sum+((*it)/2);
                }
                cout<<sum;
            }
            return 0;
        }

4)Nesting in STL maps and sets-
    -when, for example, a set or pair is stored as a key in a map, it is stored in sorted order
     by comparing with the first distinct elements.
    -example
        #include <bits/stdc++.h>
        using namespace std;
        int main(){
            map<pair<string,string>,vector<int>>m;
            int n;
            cin>>n;
            for(int i=0;i<n;++i){
                string fn,ln;
                int cnt;
                cin>>fn>>ln>>cnt;
                for(int i=0;i<cnt;++i){
                    int x;
                    cin>>x;
                    m[{fn,ln}].push_back(x);
                }
                for(auto &val:m){
                    auto fullname=val.first;
                    auto marks=val.second;
                    cout<<fullname.first<<" "<<fullname.second<<endl;
                    cout<<marks.size()<<endl;
                    for(auto &mr:marks){
                        cout<<mr<<" ";
                    }
                    cout<<endl;
                }
            }
            return 0;
        }
    -another question
        #include <bits/stdc++.h>
        using namespace std;
        int main(){
            map<int,multiset<string>>m;//same name and same marks walo ke liye multiset use kia
            int n;
            cin>>n;
            while(n--){
                int marks;
                string name;
                cin>>name>>marks;
                m[marks].insert(name);
                auto crit=--m.end();
                while(true){
                    auto &studentname=(*crit).second;
                    int studentmarks=(*crit).first;
                    for(auto val:studentname){
                        cout<<val<<" "<<studentmarks<<endl;
                    }
                    if(crit==m.begin()){
                        break;
                    }
                    crit--;
                }
            }
            return 0;
        }
        // inducing negative marks can solve the problem without iterators
            #include <bits/stdc++.h>
            using namespace std;
            int main(){
                map<int,multiset<string>>m;
                int n;
                cin>>n;
                while(n--){
                    int marks;
                    string name;
                    cin>>name>>marks;
                    m[-1*marks].insert(name);
                    m[-1*marks].insert(name);
                       for(auto &mrk_std_pr:m){
                            auto &studentname=mrk_std_pr.second;
                            int studentmarks=mrk_std_pr.first;
                            for(auto val:studentname){
                                cout<<val<<" "<<-1*studentmarks<<endl;
                            }
                        }
                }
                return 0;
            }

5)Stacks and queues
    Stacks
    -LIFO data structures (last in first out)
    -it means that, the element that is put first comes at last, and vice versa
    -we can only know the top element and the size of the stack (assume stack as a bucket with elements pouring)
    -mainly 3 operations, push (it adds the element to the stack), pop (it removes the element from the stack) and top (it hellps to see the top element of the stack)
    -code for stack
        #include <bits/stdc++.h>
        using namespace std;
        int main(){
            stack<int>s;
            //taking input
            s.push(1);
            s.push(2);
            s.push(3);
            s.push(4);
            //printing the element
            while(! s.empty()){//s.empty(returns a boolean)
                cout<<s.top()<<endl;
                s.pop();//removes the element so that we can reach next element
            }
            //4 will be printed first
            return 0;
        }
    -balanced bracket matching (https://bit.ly/3de6cDV_hackerrankques)
        #include <bits/stdc++.h>
        using namespace std;
        unordered_map<char,int>br={{'(',-3},{'[',-2},{'{',-1},{'}',1},{']',2},{')',3}};//global decleration
        string isBalanced(string s){
            stack<char>st;
            for(char c:s){
                if(br[c]<0){//indicates opening brackets
                    st.push(c);
                }
                else{//this else is for closing brackets
                    if(st.empty()){//if the stack is empty, then the brackets are not balanced
                        return "NO";
                    }
                    char top=st.top();
                    st.pop();
                    if(br[c]+br[top]!=0){//closing brackets not present, br[c] is the closing bracket ki value
                        return "NO";
                    }
                }
            }
            if(st.empty()){
                return "YES";
            }
            return "NO";
        }
        int main(){
            ios_base::sync_with_stdio(false);
            cin.tie(NULL);
            int t;
            cin>>t;
            while(t--){
                string s;
                cin>>s;
                cout<<isBalanced(s)<<endl;
            }
            return 0;
        }
    -next greater element(to the right) using stacks ({4,5,25,7,8}--->NGE{5,25,25,-1,8,-1})
        


    Queues
    -FIFO data structures (first in first out)
    -assume like a horizontal pipe
    -push: (pushes element in the end (somewhat like in vector))
    -pop: (front element of the  queue is removed)
    -front: seeing the value of frontmost element
    -code for queue
        #include <bits/stdc++.h>
        using namespace std;
        int main(){
            queue<int>q;
            //taking input
            q.push(14);
            q.push(24);
            q.push(13);
            q.push(40);
            //printing the element
            while(! q.empty()){//q.empty (returns a boolean)
                cout<<q.front()<<endl;
                q.pop();//deletes the element so that we can reach next element
            }
            //14 will be printed first
            return 0;
        }






ITERATORS
    -pointer like structures that help in accessing the values in STL containers
    -as vectors are index based containers, we can easily accesss them, but some other containers like maps, sets are not index based container
     so iterators are used to access the value of such containers.
    -there are two iterators, viz., .begin() and .end()
     (taking an example of vector).begin() points at the first element, while .end() points at the next of last element.
    -declaration
        vector<int>::iterator it;
        it=v.begin();
        cout<<(*it)<<endl;// prints the first element
    -accessing the elements of the container
        vector<int>v={4,6,2,7,33,56};
        vector<int>::iterator it;
        for(it=v.begin();it<v.end();it++){
            cout<<(*it)<<" ";
        }
        -there is a difference between it++ an it+1
         it++ : moves to next iterator
         it+1 : moves to next location
            eg- for a vector, both work as memory is allocated continually,
                while for some containers like sets or maps, it++ is valid and not it+1 because in those containers
                memory location are not continuous
        -iterators used for a pair
            vector<pair<int,int>>vp={{1,2},{4,5},{9,0},{7,1}};
            vector<pair<int,int>>::iterator it;
            for(it=vp.begin();it<vp.end();it++){
                cout<<(*it).first<<" "<<(*it).second<<endl;
            }
            // or, for(it=vp.begin();it<vp.end();it++){
            //      cout<<(it->first)<<" "<<(it->second)<<endl;
            //    }
        -writing iterators in short(C++ 11 onwards)
            #RANGE BASED LOOPS & AUTO KEYWORD
                1.Range based loop
                    vector<int>v={4,6,3,2,2,4,5};
                    for(int &value:v){ //copy of value created if '&' is not used
                        cout<<value<<" ";
                    }//in place of v, any container can be used

                    vector<pair<int,int>>v={{2,4},{6,1},{0,4}};
                    for(pair<int,int> &value:v){
                        cout<<value.first<<" "<<value.second<<endl;
                    }
                2.'auto' keyword
                    -if we say auto a=1 and print it, C++ automatically assumes the data type to be int.
                     so similarly it can be used to reduce the length of code used to create an iterator
                     eg-
                        instead of writing
                        vector<pair<int,int>>::iterator it;
                            for(it=vp.begin();it<vp.end();it++){
                            cout<<(*it).first<<" "<<(*it).second<<endl;
                        }
                        we can simply write,
                        for(auto it=v.begin();it<v.end();it++){
                            cout<<(*it).first<<" "<<(*it).second<<endl;
                        }
                    -using auto for range based loop in pair,
                     eg-instead of writing
                        vector<pair<int,int>>v={{2,4},{6,1},{0,4}};
                        for(pair<int,int> &value:v){
                            cout<<value.first<<" "<<value.second<<endl;
                        }
                        we can write,
                        vector<pair<int,int>>v={{2,4},{6,1},{0,4}};
                        for(auto &value:v){
                            cout<<value.first<<" "<<value.second<<endl;
                        }











*/