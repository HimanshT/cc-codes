// Given a string in roman no format (s)  your task is to convert it to an integer . Various symbols and their values are given below.
// I 1
// V 5
// X 10
// L 50
// C 100
// D 500
// M 1000

int romanToDecimal(string &str) { ///xxvv
	// code here
	unordered_map<char, int> umap; //cmxv1 = 100+1000+
	umap['I'] = 1;
	umap['V'] = 5;
	umap['X'] = 10;
	umap['L'] = 50;
	umap['C'] = 100;
	umap['D'] = 500;
	umap['M'] = 1000;
	int decimal = 0;
	for (int i = 0; i < str.length();)
	{
		if (umap[str[i + 1]] > umap[str[i]] && i < (str.length() - 1))
		{
			decimal += umap[str[i + 1]] - umap[str[i]];
			i += 2;
		}
		else
		{
			decimal += umap[str[i]];
			i++;
		}
	}
	return decimal;
}