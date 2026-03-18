#ifndef contact_h  
#define contact_h 

typedef struct {
	char name[20];
	char phone[20];
} contact;

void modify_contact();
void sort_contact();
void save_contact();
void read_contact();
void add_contact();
void show_contact();
void find_contact();
void delete_contact();

#endif  // !contact_h  
