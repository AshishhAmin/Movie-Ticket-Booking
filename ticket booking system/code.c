#include <stdio.h>
#include <string.h>

#define MAX_MOVIES 10
#define MAX_NAME_LENGTH 50
#define MAX_TICKETS 100

struct Movie
 {
    char name[MAX_NAME_LENGTH];
    int tickets_available;
     char director[100];
     int rating;
     int cost;
};

struct Movie movies[MAX_MOVIES];
int movie_count = 5;

void add_movie(void)
 {
        strcpy(movies[0].name, "KGF");
        /*strcpy(movies[0].director, "Prashanth");
        movies[0].rating = 5;
        movies[0].cost = 150;*/
        strcpy(movies[1].name, "AVATAR");
        strcpy(movies[2].name, "PATHAAN");
        strcpy(movies[3].name, "FARZI");
        strcpy(movies[4].name, "RRR");
        movies[0].tickets_available = 100;
         movies[1].tickets_available = 100;
          movies[2].tickets_available = 100;
           movies[3].tickets_available = 100;
            movies[4].tickets_available = 100;
    // printf("This is testing");
//     if (movie_count == MAX_MOVIES) 
//     {
//         printf("\nCannot add more movies. Maximum limit reached.\n");
//         return;
//     }
//     printf("\nEnter movie name: ");
//     scanf("%s", movies[movie_count].name);
//     movies[movie_count].tickets_available = MAX_TICKETS;
//     movie_count++;
//      printf("Enter movie director: ");
//   scanf("%s", movies[movie_count].director);
//    printf("Enter movie rating (1-5): ");
//   scanf("%d", &movies[movie_count].rating);
//   printf("Enter Ticket Price:- ");
// 	scanf("%d",&movies[movie_count].cost);
//  printf("\nMovie added successfully.\n");
}
void display_movies(void) 
{
    printf("\nAvailable movies:\n");

    for (int i = 0; i < movie_count; i++) {
        printf("%d. %s (%d tickets available)\n", i + 1, movies[i].name, movies[i].tickets_available);
    }
}
void print_seat_matrix(int booked){
	for (int i = 1,cnt=1; i<=10; i++){
		for (int j = 1;j<=10; j++, cnt++){
			if (cnt <= booked)
				printf("x ");
			else
				printf("* ");
		}
		printf("\n");
	}
}
void book_ticket(void) 
{
    int movie_index;
    int tickets;
    int total_amount,total_seat;
    int age;

    display_movies();
    printf("\nEnter movie number: ");
    scanf("%d", &movie_index);
    movie_index--;
    if (movie_index < 0 || movie_index > movie_count) 
    {
        printf("\nInvalid movie number.\n");
        return;
    }
	print_seat_matrix(100 - movies[movie_index].tickets_available);
    printf("\nEnter number of tickets: ");
    scanf("%d", &tickets);
    if (tickets > movies[movie_index].tickets_available) 
    {
        printf("\nNot enough tickets available.\n");
        return;
    }
   // printf("%d %d", movies[movie_index].tickets_available, movie_index);
    movies[movie_index].tickets_available -= tickets;
  
  float ticket_price ;

  printf("Enter your age: ");
  scanf("%d", &age);

  if (age < 10) 
  {
    ticket_price = tickets*(800 * 0.5);
  }
  else if(age>10 && age<65)
  {
    ticket_price=tickets*800;
  }
   else if (age >= 65) 
  {
    ticket_price = tickets*(800 * 0.75);
  }

  printf("The ticket price is: %.2fRupees\n", ticket_price);
    printf("\nBooking successful. Enjoy the movie!\n");
}

int main(void) {
    int choice;
    add_movie();
    while (1) {
        printf("\nMovie Ticket Booking System\n");
        printf("1. Display movies\n");
        printf("2. Add movie\n");
        printf("3. Book ticket\n");
        printf("4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                display_movies();
                break;
            case 2:
                add_movie();
                break;
            case 3:
                book_ticket();
                break;
            case 4:
                return 0;
            default:
                printf("\nInvalid choice.\n");
        }
    }

    return 0;
}
