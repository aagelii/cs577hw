#include <iostream>
#include <vector>
#include <map>
#include <iterator>

using namespace std;
int main() {
    int instances;
    cin >> instances;
    int numPages;
    for (int i = 0; i < instances; ++i) {
        cin >> numPages;
        int numReq;
        cin >> numReq;
        map<int, int> cache;
        int cur;
        map<int, int> requests;
        int hit=0;
        for (int j = 0; j < numReq; ++j) {
            cin >> cur;
            requests.insert(pair<int, int>(j, cur));
            /*requests.insert(pair<int, int>(cur, j));
            if(cache.count(cur)){
                hit++;
                continue;
            }
            if(cache.size()<numPages){
                cache.insert(pair<int,int>(cur, j));
                requests.erase(j);
            }
            else{

            }*/

        }
        map<int, int>::iterator k;
        for (k = requests.begin(); k != requests.end(); ++k) {
            /*if(binary_search(cache.begin(), cache.begin(), k->second)){
                hit++;
                continue;
            }*/
            if(cache.count(k->second)){
                hit++;
                continue;
            }
            if(cache.size()<numPages){
                cache.insert(pair<int,int>(k->second, k->first));
                requests.erase(k);
            }
            else{
                int maxIndex=0;
                for (auto & request : requests)
                    if (request.second == k->second)
                        maxIndex=request.first
            }
        }


        cout << numReq - hit << endl;
        /*int hit = 0;
        bool searchStatus;
        for (int k = 0; k < numReq; k++) {
            searchStatus = [] ( int key, vector<int>& fr){
                for (int i : fr)
                    if (i == key)
                        return true;
                return false;
            }(pages[k],cache);
            if (searchStatus) {
                hit++;
                continue;
            }
            if (cache.size() < numPages)
                cache.push_back(pages[k]);
            else {
                int j = [] (const int pg[], vector<int>& fr, int pn, int index){
                    int res = -1, farthest = index;
                    for (int i = 0; i < fr.size(); i++) {
                        int j;
                        for (j = index; j < pn; j++) {
                            if (fr[i] == pg[j]) {
                                if (j > farthest) {
                                    farthest = j;
                                    res = i;
                                }
                                break;
                            }
                        }
                        if (j == pn)
                            return i;
                    }
                    return (res == -1) ? 0 : res;
                }(pages, cache, numReq, k + 1);
                cache[j] = pages[k];
            }
        }
        cout << numReq - hit << endl;

    }*/

    }
}
/*
 * 3 - instances
 * 2 - # of pages numPages
 * 7 - # of requests numReq = pn
 * 1 2 3 2 3 1 2 - requests
 * 4 - # of pages
 * 12 - # of requests
 * 12 3 33 14 12 20 12 3 14 33 12 20 - requests
 * 3 - # of pages
 * 15 - # of requests
 * 1 2 3 4 5 1 2 3 4 5 1 2 3 4 5 - requests
 * for each instance should output # of page faults
 */