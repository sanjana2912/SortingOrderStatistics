
class kthSmallest
{
  private:
  int n;
  
  public:
    kthSmallest(int n);
    int getkthSmallest();
    int static calcKthSmallest(int arr[], int l, int r, int k);
}; 