#include <iostream>
#include <unordered_map>
using namespace std;

int main() {
  unordered_map<string, float> umap;

  // inserting values by using [] operator
  umap["Unordered"] = 0.0;
  umap["Map"] = 0.1;
  umap["Implemention"] = 0.2;

  // Traversing an unordered map
  for (auto x : umap)
    cout << x.first << " " << x.second << endl;

  cout << "bucket count and size " << umap.bucket_count()<< " "
       << umap.bucket_size(1);
  return 0;
}