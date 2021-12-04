#include <iostream>
#include <string>
#include <vector>

int main()
{
	int  size1, size2, enter, count1, count2;
	std::vector < int > array1;
	std::vector < int > array2;
	std::vector < int > lcs;

	std::cout << "Enter the size of the first sequence" << '\n';

	std::cin >> size1;

	std::cout << "Enter the first sequence" << '\n';

	for (auto i = 0; i < size1; ++i)
	{
		std::cin >> enter;
		array1.push_back(enter);
	}

	std::cout << "Enter the size of the second sequence" << '\n';

	std::cin >> size2;

	std::cout << "Enter the second sequence" << '\n';

	for (auto i = 0; i < size2; ++i)
	{
		std::cin >> enter;
		array2.push_back(enter);
	}

	std::vector < std::vector < int > > matrix(size1 + 1, std::vector <int> (size2 + 1, 0));

	for (auto i = 1; i < size1 + 1; ++i)
	{
		for (auto j = 1; j < size2 + 1; ++j)
		{
			if (array1[i - 1] == array2[j - 1])
			{
				matrix[i][j] = matrix[i - 1][j - 1] + 1;
			}
			else
			{
				matrix[i][j] = std::max(matrix[i - 1][j],matrix[i][j - 1]);
			}
		}
	}

	count1 = size1;
	count2 = size2;
	
	while (count1 >= 1 and count2 >= 1)
	{
		if (matrix[count1][count2 - 1] == matrix[count1][count2])
		{
			count2 -= 1;
		}

		else
		{
			if (matrix[count1 - 1][count2] == matrix[count1][count2])
			{
				count1 -= 1;
			}

			else
			{
				if (matrix[count1 - 1][count2 - 1] != matrix[count1][count2])
				{
					lcs.push_back(array1[count1 - 1]);
					count1 -= 1;
					count2 -= 1;
				}

			}
			
		}
	}

	std::reverse(lcs.begin(), lcs.end());

	for (auto i = 0; i < lcs.size(); ++i)
	{
		std::cout << lcs[i] << ' ';
	}
	return 0;
}