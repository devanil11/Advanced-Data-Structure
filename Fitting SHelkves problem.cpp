#include<iostream>
using namespace std;
 
void Fitting_shelf(int wall_length, int smaller, int larger)
{
    // Output variables
    int smaller_used = 0, larger_used = 0, min_empty = wall_length;
    // p and q are no of shelves of smaller length  and larger length respectively.
    // remaining_length is the length which can't be filled in this iteration.
    int p;
    int q = -1; //For sake of programming simplicity, it has been declared as -1.
    int remaining_length;
    while (wall_length >= larger) 
    {
        // place one more shelf of larger length 
        q += 1;
        if(q>0)
        wall_length = wall_length - larger;
        //As many shelves of smaller length are to be placed till no more smaller length ones can be placed.
        p = wall_length / smaller;
        remaining_length = wall_length % smaller;
 
        //Output variables are to be updated if remaining_length is lesser than previous least empty space.
        if (remaining_length <= min_empty) 
        {
            smaller_used = p;
            larger_used = q;
            min_empty = remaining_length;
        }
    }
    cout<<"Number of smaller length shelf used is"<<smaller_used<<endl;
    cout<<"Number of larger length shelf used is"<<larger_used<<endl;
    cout<<"Least empty space or the corresponding number of shelves is"<<min_empty<<endl;
}

int main()
{
    int wall,smaller,larger;
    cout<<"Enter the length of the wall";
    cin>>wall;
    cout<<"Enter the length of the smaller shelf";
    cin>>smaller;
    cout<<"Enter the length of the larger shelf";
    cin>>larger;
    Fitting_shelf(wall,smaller,larger);
    return 0;
}
