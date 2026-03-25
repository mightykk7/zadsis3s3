// Rogov_pr31_3prakt.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

#include <iostream>


struct ForeignLanguages {
    int count;
    char languagesArr[5][20];
};

union LanguageInfo {
    int birthYear;
    ForeignLanguages languages;
};

struct Person {
    char FIO[80];
    char gender;
    bool isMarried;
    bool hasForeignLang;
    LanguageInfo languageInfo;
};

int main()
{
    setlocale(LC_ALL, "");
    Person people[8];

    strcpy_s(people[0].FIO, "Иванов Иван Иванович");
    people[0].gender = 'M';
    people[0].isMarried = false;
    people[0].hasForeignLang = false;
    people[0].languageInfo.birthYear = 1990;

    strcpy_s(people[1].FIO, "Кузнецов Кузнец Кузнечин");
    people[1].gender = 'M';
    people[1].isMarried = true;
    people[1].hasForeignLang = true;
    people[1].languageInfo.languages.count=1;
    strcpy_s(people[1].languageInfo.languages.languagesArr[0], "Английский");

    strcpy_s(people[2].FIO, "Вакулко Екатерина Андреевна");
    people[2].gender = 'F';
    people[2].isMarried = true;
    people[2].hasForeignLang = false;
    people[2].languageInfo.birthYear = 1994;

    strcpy_s(people[3].FIO, "Самарина Надежда Алексеевна");
    people[3].gender = 'F';
    people[3].isMarried = true;
    people[3].hasForeignLang = true;
    people[3].languageInfo.languages.count = 3;
    strcpy_s(people[3].languageInfo.languages.languagesArr[0], "Английский");
    strcpy_s(people[3].languageInfo.languages.languagesArr[1], "Французкий");
    strcpy_s(people[3].languageInfo.languages.languagesArr[2], "Испанский");

    strcpy_s(people[4].FIO, "Смирнов Василий Николаевич");
    people[4].gender = 'M';
    people[4].isMarried = false;
    people[4].hasForeignLang = false;
    people[4].languageInfo.birthYear = 1998;

    strcpy_s(people[5].FIO, "Аванов Еван Еванович");
    people[5].gender = 'M';
    people[5].isMarried = false;
    people[5].hasForeignLang = false;
    people[5].languageInfo.birthYear = 2000;

    strcpy_s(people[6].FIO, "Саняв Саня Санович");
    people[6].gender = 'M';
    people[6].isMarried = true;
    people[6].hasForeignLang = false;
    people[6].languageInfo.birthYear = 1995;

    strcpy_s(people[7].FIO, "Индреев Индрей Индреевич");
    people[7].gender = 'M';
    people[7].isMarried = false;
    people[7].hasForeignLang = false;
    people[7].languageInfo.birthYear = 1992;

    Person singleMen[8];
    int count = 0;

    for (int i = 0; i < 8; i++) {
        if (people[i].gender == 'M' && !people[i].isMarried && !people[i].hasForeignLang) {
            singleMen[count] = people[i];
            count++;
        }
    }

    //пузырьковая сортировка
    for (int i = 0; i < count - 1; i++) {
        for (int j = 0; j < count - i - 1; j++) {

            //берём две фамилии
            char tempFIO1[80], tempFIO2[80];
            strcpy_s(tempFIO1, singleMen[j].FIO);
            strcpy_s(tempFIO2, singleMen[j + 1].FIO);

            //обрезаем на первом пробеле
            for (int k = 0; tempFIO1[k] != '\0'; k++) {
                if (tempFIO1[k] == ' ') {
                    tempFIO1[k] = '\0';
                    break;
                }
            }
            for (int k = 0; tempFIO2[k] != '\0'; k++) {
                if (tempFIO2[k] == ' ') {
                    tempFIO2[k] = '\0';
                    break;
                }
            }

            //сравниваем фамилии
            if (strcmp(tempFIO1, tempFIO2) > 0) {
                Person temp = singleMen[j];
                singleMen[j] = singleMen[j + 1];
                singleMen[j + 1] = temp;
            }
        }
    }

    std::cout << "Список холостых мужчин без знания иностранных языков по фамилиям:\n\n";

    for (int i = 0; i < count; i++) {
        std::cout << "ФИО: " << singleMen[i].FIO << std::endl;
        std::cout << "Год рождения: " << singleMen[i].languageInfo.birthYear << "\n\n";
    }

    system("pause");
}

