#include <iostream>
#include <vector>

using namespace std;
int main() {
    int instances;
    cin>>instances;
    int numPages;
    for(int i=0;i<instances;++i){
        cin>>numPages;
        // vector<int>pages(numPages);
        int pageFaults=0;
        int pages[numPages]; // size 2
        for(int j=0; j<numPages; ++j){
            pages[j]=0;
        }
        int numReq=0;
        cin>>numReq; // 7 req
        int curPage=0;
        vector<int> requests; // 1 2 3 2 3 1 2
        for(int k=0;k<numReq;++k){
            cin>>curPage;
            requests.emplace_back(curPage);
        }
        for(int x=0; x<requests.size(); ++x){
            bool found=false;
            /*for(int p = 0; p<numPages; ++p){
                cout<<pages[p]<<" ";
            }
            cout<<endl;*/
            for(int y=0; y<numPages;++y){
                if(pages[y]==requests.at(x)){
                    found=true;
                    break;
                }
            }
            //cout<<requests.at(x)<<endl;
            if(!found){ // not found
                ++pageFaults;
                if(pages[numPages-1]==0){ // space available
                    for(int z=0; z<numPages; ++z){ // find empty space
                        if(pages[z]==0){
                            pages[z] = requests.at(x);
                            break;
                        }
                    }
                }
                else{
                    int index=0;
                    int pageIndex=0;
                    for(int z=0; z<numPages; ++z){ // going thru pages[]
                        bool exists=false;
                        int cur=0;
                        for(int a=x; a<requests.size(); ++a){
                            if(pages[z]==requests.at(a)){ // found in req
                                if(a>index){
                                    index=a;
                                    pageIndex=z;
                                    exists=true;
                                    break;
                                }
                                exists=true;
                                //cout<<"found!"<<requests.at(a)<<endl;
                                break;
                            }
                            else{ // assume that 1 doesn't exist in pages[]
                                //cout<<"why am i here???"<<endl;
                                cur=z;
                            }
                        }
                        if(!exists){
                            pageIndex=cur;
                            break;
                        }
                    }
                    pages[pageIndex]=requests.at(x);
                }
            }
        }
        cout<<pageFaults<<endl;
    }
    return 0;
}
/*
 * 3 - instances
 * 2 - # of pages
 * 7 - # of requests
 * 1 2 3 2 3 1 2 - requests
 * 4 - # of pages
 * 12 - # of requests
 * 12 3 33 14 12 20 12 3 14 33 12 20 - requests
 * 3 - # of pages
 * 15 - # of requests
 * 1 2 3 4 5 1 2 3 4 5 1 2 3 4 5 - requests
 * for each instance should output # of page faults
 */
