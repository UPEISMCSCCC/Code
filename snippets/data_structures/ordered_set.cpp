template <typename T>
using oset = tree<T,null_type,less<T>,rb_tree_tag,tree_order_statistics_node_update>;

int main()
{
	oset<int> o_set;
	o_set.insert(5); o_set.insert(1); o_set.insert(3); 
  
	// get second smallest element
	cout << *(o_set.find_by_order(1));
  
	// number of elements less than k=4 
	cout << ' ' << o_set.order_of_key(4) << '\n';
}