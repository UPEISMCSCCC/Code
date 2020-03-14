typedef tree<int,null_type,less<int>,rb_tree_tag,tree_order_statistics_node_update> ordered_set;

int main()
{
	ordered_set o_set; 
	o_set.insert(5); o_set.insert(1); o_set.insert(3); 
  
	// get second smallest element
	cout << *(o_set.find_by_order(1)) << '\n';
  
	// number of elements less than k=4 
	cout << o_set.order_of_key(4) << '\n';
}