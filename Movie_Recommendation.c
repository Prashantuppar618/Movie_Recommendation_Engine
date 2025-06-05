#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct recommendation_data
{
    char movie_name[30];
    char recommendation_name[30];
    int viewers;
    char genre[20]; // New feature: Genre
};

typedef struct recommendation_data RD;

RD search_list[200];
int global_count = 0;

void welcome()
{
    int i = 0;
    for (i = 0; i < 80; i++)
        printf("*");

    printf("\n\n\t\t\t\tRECOMMENDATION ENGINE\n\n\n");

    for (i = 0; i < 80; i++)
        printf("*");

    printf("\n\n");
}

void load_from_file()
{
    FILE *fp;
    fp = fopen("MovieIndex.txt", "r");

    if (fp == NULL)
    {
        printf("File Not found\n");
        return;
    }

    while (fscanf(fp, "%s %s %d %s", search_list[global_count].movie_name,
                  search_list[global_count].recommendation_name,
                  &search_list[global_count].viewers, search_list[global_count].genre) == 4)
    {
        printf("%s %s %d %s\n", search_list[global_count].movie_name,
               search_list[global_count].recommendation_name, search_list[global_count].viewers,
               search_list[global_count].genre);
        global_count++;
    }

    fclose(fp);
}

void refine_search(char *query, char *genre)
{
    for (int i = 0; i < global_count; ++i)
    {
        if (strstr(search_list[i].movie_name, query) && strcmp(search_list[i].genre, genre) == 0)
        {
            printf("%s %s %d %s\n", search_list[i].movie_name, search_list[i].recommendation_name,
                   search_list[i].viewers, search_list[i].genre);
        }
    }
}

int compare_viewers(const void *a, const void *b)
{
    return ((RD *)b)->viewers - ((RD *)a)->viewers;
}

void display_recommendations(RD *results, int result_count)
{
    if (result_count > 0)
    {
        for (int i = 0; i < result_count; ++i)
        {
            for (int j = 0; results[i].recommendation_name[j]; j++)
            {
                if (results[i].recommendation_name[j] == '-')
                    results[i].recommendation_name[j] = ' ';
            }
            printf("%s\n", results[i].recommendation_name);
        }
    }
    else
    {
        printf("NO RECOMMENDATIONS\n");
    }
}

void add_movie_data()
{
    FILE *fp;
    char movie_name[30], recommendation_name[30], genre[20];
    int viewers;

    printf("Enter movie name: ");
    scanf("%s", movie_name);

    printf("Enter recommendation name: ");
    scanf("%s", recommendation_name);

    printf("Enter number of viewers: ");
    scanf("%d", &viewers);

    printf("Enter genre: ");
    scanf("%s", genre);

    fp = fopen("MovieIndex.txt", "a");

    if (fp == NULL)
    {
        printf("File Not found\n");
        return;
    }

    fprintf(fp, "%s %s %d %s\n", movie_name, recommendation_name, viewers, genre);

    fclose(fp);

    load_from_file();
}

void menu()
{
    int choice;
    char query[30], genre[20];
    RD results[200];
    int result_count;

    do
    {
        printf("\nMENU\n");
        printf("1. Search recommendations\n");
        printf("2. Add new movie data\n");
        printf("3. Sort movies based on viewers\n");
        printf("4. Display all movies\n");
        printf("5. Exit\n");

        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice)
        {
        case 1:
            printf("Enter search query (in lowercase with - instead of space): ");
            scanf("%s", query);

            printf("Enter genre: ");
            scanf("%s", genre);

            if (strchr(query, ' ') != NULL)
            {
                printf("Invalid input format. Please use - instead of space.\n");
                break;
            }

            refine_search(query, genre);
            result_count = 0;

            for (int i = 0; i < global_count; ++i)
            {
                if (strstr(search_list[i].movie_name, query) && strcmp(search_list[i].genre, genre) == 0)
                {
                    strcpy(results[result_count].recommendation_name, search_list[i].recommendation_name);
                    results[result_count].viewers = search_list[i].viewers;
                    result_count++;
                }
            }

            display_recommendations(results, result_count);
            break;

        case 2:
            add_movie_data();
            break;

        case 3:
            qsort(search_list, global_count, sizeof(RD), compare_viewers);
            printf("Movies sorted based on viewers.\n");
            break;

        case 4:
            printf("All Movies:\n");
            for (int i = 0; i < global_count; ++i)
            {
                printf("%s %s %d %s\n", search_list[i].movie_name, search_list[i].recommendation_name,
                       search_list[i].viewers, search_list[i].genre);
            }
            break;

        case 5:
            printf("Exiting the program. Goodbye!\n");
            break;

        default:
            printf("Invalid choice. Please enter a valid option.\n");
        }
    } while (choice != 5);
}

int main()
{
    welcome();
    load_from_file();
    menu();

    return 0;
}
