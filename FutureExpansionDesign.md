# Discuss
Both feature will both need to run validator at first, and **it is skipped here**.  
1. XML Comparison Feature  
   I assume that if all elements and text inside elements are same between two XML string, then thay are same in structure.
   
   To achieve comparison, we need to store all elements and text inside with other, then we can compare them. Based on the rule of judging "same", some function may also needed. For example, a case changer is needed if upper case and lower case are considered as same.        

2. Search Feature  
   Based on requirement, search can be simple or tricky.   

   If it is the simplest way, which is search the first node same as input. To achieve this, find out the position of opening tag and corresponding closing tag, then output the string between them.  

   If there will be more functions like searching with regular expression or searching all nodes satisfy the input, then this can be tricky.  

# Classes and functions
As wrote above, searching can be tricky so here I will design for the comparison feature.  

```cpp
bool CompareXml(const std::string &input1, const std::string &input2) {
	// Validate for input1 and input2
	{
		// ...
	}

	// Store tags and text in order
	std::stack<string> st1;
	std::stack<string> st2;

	// Compare 2 stacks
	bool ret = false;
	{
		// ...
	}

	return ret;
}
```
