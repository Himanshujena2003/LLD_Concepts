#include<bits/stdc++.h>
using namespace std;

// Thsi is not a good architecture violating (SRP,OCP)
// class DocsEditor{
//     private:
//     vector<string>page;
//     string docs;

//     public:
//     // adding text
//     void addText(string text){
//         page.push_back(text);
//     }
    
//     // adding image
//     void addImage(string path){
//         page.push_back(path);
//     }

//     // render page
//     string renderDocument(){
//         if(docs.empty()){
//             string result;
//             for(auto element:page){
//                 if(element.size() > 4 && (element.substr(element.size()-4)==".jpg" || 
//                   element.substr(element.size()-4)==".png")){
//                     result += "[Image: " + element + "]" + "\n"; 
//                 }
//                 else{
//                     result += element + "\n";
//                 }
//             }
//             docs = result;
//         }
//         return docs;
//     }

//     // save to file
//     void saveToFile(){
//         ofstream file("document.txt");
//         try{
//             if(file.is_open()){
//                 file<<docs;
//                 file.close();
//             }    
//             else throw "Unable to open file";
            
//         }
//         catch(exception&e){
//             cout<<e.what()<<endl;
//         }
//     }
// };


int main(){
    
}