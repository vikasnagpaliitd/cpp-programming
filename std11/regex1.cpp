#include <iostream>
#include <regex>
using namespace std;


int main()
{
  string target("123-456-789 111-222-333 444-555-666");
  regex pattern("([0-9]{3})-([0-9]{3})-([0-9]{3})");

  smatch results;

  bool ret = regex_search(target, results, pattern);
  if (ret)
  {
     cout << "results.size()=" << results.size() << endl;
     cout << "Matches are: ";
     for (auto str : results)
		cout << str << " ";
     cout << endl;
  }

  // Iterating through all matches
  //auto iter = regex_iterator<std::string::const_iterator>(target.begin(), target.end(), pattern);
  auto iter = sregex_iterator(target.begin(), target.end(), pattern);
  //for(; iter != regex_iterator<std::string::const_iterator>(); iter++)
  for(; iter != sregex_iterator(); iter++)
  {
     cout << "iter->size()=" << results.size() << endl;
     cout << "Matches are: ";
     for (auto str : *iter)
		cout << str << " ";
     cout << endl;

  }

  return 0;
}
