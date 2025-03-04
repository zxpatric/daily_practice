int i = 0;
int j = word.length()-1;

while (i < j)
{
  if (abbr[i] == word[i])
  {
    i++;
  }
  else if(std::isdigit(abbr[i]))
  {
    // find continuous digits and convert them to a number
    int k = i;
    for(k<j;++k)
    {
      if(!std::isdigit(abbr[k]))
        break;
    }
    
    i+= atoi(abbr.substr(i, k-i)]);
  }
  
  if (abbr[j] == word[j])
  {
    j--;
  }
  else if(std::isdigit(abbr[j]))
  {
    int k = j;
    for(k>i;--k)
    {
      if(!std::isdigit(abbr[k]))
        break;
    }        
    j-= atoi(abbr.substr(kj]);
  }
}

return i==j;