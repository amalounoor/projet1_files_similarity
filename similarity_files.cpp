#include<iostream> //input output library
#include<fstream>  //files manipulation library
#include<vector>   //vectors manipulation library
#include<string>   //strings manipulation library
#include<math.h>   //math library .I inculde this library to use the sqrt function
    using std::vector;
    using std::string;
    using std::ifstream;
//functions used
    vector<string> readfile(string);
    //return a vector that contains a file words
    void freq_fun(vector<string>vfile1,vector<string>vfile2,vector<int>&vfreq1,vector<int>&vfreq2);
    //retun of the frequency of each words in file1 and file2
    int produit_vect(vector<int>,vector<int>);
    //retun the dot product between two vectors
    double cos_similarity(vector<int>,vector<int>);
     //retun the cos similarity between two vectors

int main(){
    using namespace std;
    //1-read the two files and generate the vector of word for each file
    string nf1; //nf1 --->the name.txt of the first file
    string nf2; //nf1 --->the name.txt of the second file
    cout<<"Enter the tow files\n"; 
    cin>>nf1>>nf2; //read the two files names
    vector <string> vf1; //vf1--->vector of the first file word
    vector <string> vf2; //vf1--->vector of the second file word
    vf1=readfile(nf1); 
    vf2=readfile(nf2);
    //2-calculate the frequency of all the word (word file1 + word file2 -intersection(word file1,word file2))in the two vectors
    vector<int>vfreq1; //vfreq1--->vector of the frequency of all the word in vf1
    vector<int>vfreq2; //vfreq2--->vector of the frequency of all the word in vf2
    freq_fun(vf1,vf2,vfreq1,vfreq2);
    //3-calculate the similarity 
    double sim; //sim--> the similarity value between vfreq1 and vfreq2
    sim=cos_similarity(vfreq1,vfreq2);
    cout<<"similarity="<<""<<sim*100<<"%";
}

vector<string>readfile(string nf){
    ifstream file(nf);
    //inserting word from a file to a vector
    string word;
    vector <string> vf;
    while (file>>word)
    {
        vf.push_back(word);
    }
        file.close();
    return(vf);
}

void freq_fun(vector<string>vfile1,vector<string>vfile2,vector<int>&vfreq1,vector<int>&vfreq2){
    //calculate the frequency of each file 1 words in file1 and file 2
    for (int i = 0; i < vfile1.size(); i++)
    {
        if (vfile1[i]!="_")
        {   int freq2=0;
            int k=0;
            
            while (k<vfile2.size())
            {
                if (vfile1[i]==vfile2[k])
                {
                    freq2++;
                    vfile2[k]="_";
                }
                k++;
            }
             vfreq2.push_back(freq2);
            int j=i;
            int freq1=0;
            while (j<vfile1.size())
            {
                if (vfile1[i]==vfile1[j])
                {
                    freq1++;
                    vfile1[j]="_";
                }
                j++;
            }
            vfreq1.push_back(freq1);
           ;
            
        }
        
    }
    
     //calculate the frequency of each file 2 word in file 2 and file 1
     for (int i = 0; i < vfile2.size(); i++)
    {
        if (vfile2[i]!="_")
        {   int freq1=0;
            int k=0;
            
            while (k<vfile1.size())
            {
                if (vfile2[i]==vfile1[k])
                {
                    freq1++;
                    vfile1[k]="_";
                }
                k++;
            }
             vfreq1.push_back(freq1);
            int j=i;
            int freq2=0;
            while (j<vfile2.size())
            {
                if (vfile2[i]==vfile2[j])
                {
                    freq2++;
                    vfile1[j]="_";
                }
                j++;
            }
            vfreq2.push_back(freq2);
           ;
            
        }
        
    }
    

}
int produit_vect(vector<int>v1,vector<int>v2){
    int pv=0;
    for (int i = 0; i < v1.size(); i++)
    {
        pv=pv+v1[i]*v2[i];
    }
    
    return pv;
}
double cos_similarity(vector<int>v1,vector<int>v2){
    int pv;
    pv=produit_vect(v1,v2);

    return pv/(sqrt(v1.size())*sqrt(v2.size()));
}
