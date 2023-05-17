#include <iostream>
#include <vector>
#include <algorithm>
#include <string>

using namespace std;

struct Reference {
    string author;
    string title;
    string journal;
    int year;
};

int main() {
    vector<Reference> references = {
        {"Маслоу А.Г.", "Мотивация и личность", "", 2000},
        {"Ушинский, К. Д.", "Педагогика. Избранные работы", "М. Юрайт", 2017},
        {"Cinquin, P. A.", "Online e-learning and cognitive disabilities: A systematic review", "Computers & Education", 2019},
        {"Fershtman, C.", "Direct and indirect knowledge spillovers: the “social network” of open‐source projects", "The RAND Journal of Economics", 2011},
        {"García, M. L.", "Closed Groups, Hidden Knowledge. An Anthropological Perspective", "", 2008},
        {"Harvey, O. J.", "Conceptual systems and personality organization", "", 1961},
        {"Maslow, A. H.", "The psychology of science a reconnaissance", "", 1966},
        {"Madsen, E. S.", "The knowledge dimension of manufacturing transfers", "Strategic Outsourcing: An International Journal", 2008},
        {"Moore, J. L.", "e-Learning, online learning, and distance learning environments: Are they the same?", "The Internet and Higher Education", 2011},
        {"Mortensen, M.", "Reflected knowledge and trust in global collaboration", "Management Science", 2012},
        {"Toivonen, S.", "Context-aware trustworthiness evaluation with indirect knowledge", "Proc. of the 2nd International Semantic Web Policy Workshop (SWPW)", 2006},
        {"Wood, J.", "harnessing hidden knowledge for paradigm change", "Journal of Writing in Creative Practice", 2012},
        {"Wright, J. C.", "Conditional hedges and the intuitive psychology of traits", "Journal of personality and social psychology", 1988},
        {"Eraut, M.", "Non-formal learning and tacit knowledge in professional work", "British journal of educational psychology", 2000},
    };

    // Сортировка списка литературы с использованием лямбда-функции
    sort(references.begin(), references.end(), [](Reference r1, Reference r2) {
        if (r1.title != r2.title) {
            return r1.title < r2.title;                                                         //Сначала он сравнивает названия книг (по алфавиту), а затем сравнивает имена авторов и названия журналов
        }                                                                                       //Если две книги имеют одинаковые названия, то сравнение продолжается сравнением авторов и журналов. 
        else if (r1.author != r2.author) {                                                      //Если названия, авторы и журналы одинаковые, то книги сортируются по году издания.
            return r1.author < r2.author;                                                       //Eсли журнал на русском языке, то он идет первым.
        }              
        else if (r1.journal != r2.journal) {
            return r1.journal < r2.journal;
        }
        else {
            // Сначала проверяем язык журнала, если он на русском - он идет первым
            bool isRussian1 = r1.journal.find("рус") != std::string::npos;
            bool isRussian2 = r2.journal.find("рус") != std::string::npos;
            if (isRussian1 && !isRussian2) {
                return true;
            }
            else if (!isRussian1 && isRussian2) {
                return false;
            }
            else {
                // Если оба журнала на одном языке, то сортируем по году
                return r1.year < r2.year;
            }
        }
        });

    // Печать списка литературы
    cout << "Литература:\n";
    for (int i = 0; i < references.size(); i++) {
        cout << i + 1 << ". ";
        cout << references[i].author << ". ";
        cout << references[i].title << ". ";
        if (references[i].journal != "") {
            cout << references[i].journal << ", ";
        }
        cout << references[i].year;
    }
}