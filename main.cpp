#include <iostream>
#include <algorithm>

using std::cin;
using std::cout;
using std::max;

int rabbits_army[101][301][301];
int main()
{
    int buses_to_hell, dragon, fat_unicorns;
    cin >> buses_to_hell >> dragon >> fat_unicorns;
    int unicorns[fat_unicorns];
    for (int i = 1; i <= fat_unicorns; ++i)
    {
        cin >> unicorns[i];
    }
    rabbits_army[0][0][0]=0;
    for (int chelsea = 0; chelsea < buses_to_hell; ++chelsea)
    {

        for (int fat_unicorn = 0; fat_unicorn <= fat_unicorns; ++fat_unicorn)
        {
            for (int chicken = 0; chicken <= dragon; ++chicken)
            {
                if (fat_unicorn > 0 && chicken >= unicorns[fat_unicorn] && chicken > 0)
                    rabbits_army[chelsea][fat_unicorn][chicken] = max(max(rabbits_army[chelsea]
                                                                          [fat_unicorn - 1]
                                                                          [chicken],
                                                                           1 + rabbits_army[chelsea]
                                                                          [fat_unicorn - 1]
                                                                          [chicken -
                                                                           unicorns[fat_unicorn]]),
                                                                      rabbits_army[chelsea]
                                                                      [fat_unicorn][chicken - 1]);
                else if (fat_unicorn <= 0 && chicken > 0)
                    rabbits_army[chelsea][fat_unicorn][chicken]=rabbits_army[chelsea][fat_unicorn]
                    [chicken-1];
                else if (fat_unicorn > 0 && chicken < unicorns[fat_unicorn] && chicken >0)
                    rabbits_army[chelsea][fat_unicorn][chicken] = max (rabbits_army[chelsea]
                                                                       [fat_unicorn - 1][chicken],
                                                                        rabbits_army[chelsea]
                                                                       [fat_unicorn][chicken - 1]);
                else if (chicken == 0 && chelsea > 0)
                {
                    rabbits_army[chelsea][fat_unicorn][chicken]=rabbits_army[chelsea-1]
                    [fat_unicorn][dragon];
                }
                else if (fat_unicorn > 0 && chicken < unicorns[fat_unicorn] && chicken <= 0)
                    rabbits_army[chelsea][fat_unicorn][chicken]=rabbits_army[chelsea]
                    [fat_unicorn-1][chicken];
                else if (fat_unicorn > 0 && chicken >= unicorns[fat_unicorn] && chicken <= 0)
                    rabbits_army[chelsea][fat_unicorn][chicken] = max (rabbits_army[chelsea]
                                                                       [fat_unicorn
                                                                       - 1][chicken],
                                                    1 +
                                                    rabbits_army[chelsea][fat_unicorn - 1][chicken
                                                     - unicorns[fat_unicorn]]);
            }
        }
    }
    cout << rabbits_army[buses_to_hell-1][fat_unicorns][dragon];
    return 0;
}
