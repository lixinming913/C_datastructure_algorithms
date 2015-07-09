/*
 * c++实现最小的k个数
 */


#include<iostream>
#include<set>
#include<vector>
using namespace std;


typedef multiset<int , greater<int>> intset;
typedef multiset<int , greater<int>>::iterator setIterator;


void
GetLeastNumbers( const vector<int> & data, intset & leastnumbers, int k )
{
    leastnumbers.clear( );                                       /*清除所有元素*/
    
    if( k < 1 || data.size( ) < k )
        return;
        
    vector<int>::const_iterator iter = data.begin( );
    for( ; iter != data.end( ); ++iter ) {
        if( leastnumbers.size() < k ) {
            leastnumbers.insert(*iter);
        } else {
            setIterator iterGreatest = leastnumbers.begin();
            
            if( *iter < *iterGreatest ) {
                leastnumbers.erase(iterGreatest);
                leastnumbers.insert(*iter);
            }
        }
    }

}


void 
main()
{
    int data[ ] = {5,3,2,5,1,3,4,5};
    int n = 8;
    vector<int> vectorData;

    for(int i = 0; i < n; ++ i)
        vectorData.push_back( data[i] );

    intset leastNumbers;
    GetLeastNumbers( vectorData, leastNumbers, 4 );
    
    printf("The actual output numbers are:\n");
    
    for(setIterator iter = leastNumbers.begin(); iter != leastNumbers.end(); ++iter)
        printf("%d ", *iter);
    
    printf("\n\n");


}