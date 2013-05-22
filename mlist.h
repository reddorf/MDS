typedef struct _mlist MList;

MList *create_list();
void delete_list(MList *);
void add_element(MList *, int);
int retrieve_element(MList *, int);
int get_size(MList *);