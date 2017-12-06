#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct Entry{
	int key;
	char data[20];
}entry_t,*p_entry_t;

typedef struct hash{
	int count;
	entry_t hash_table[26];
}hash_t,*p_hash_t;

p_hash_t Create();
void Addentry(p_hash_t h,char *data);
int f(char *data);

p_hash_t Create(){  // Create hash table
	p_hash_t h;
	h = (p_hash_t)malloc(sizeof(hash_t));
	memset(h,0,sizeof(hash_t));
	return h;
}
void Addentry(p_hash_t h,char *data){ //把data放入hash table
	entry_t a;
	int i;
	a.key = f(data);
	i = a.key;
    strcpy(a.data,data);
    if(h->hash_table[i].data[0]  == 0){ //空的直接填入
    	h->hash_table[i] = a;
    	h->count++;
    	return;
    }
    i++;
    while(h->count != a.key){ //跑迴圈找到空的填入
      if(h->hash_table[i].data[0] == 0){
    	  h->hash_table[i] = a;
    	  h->count++;
    	  return;
      }
      i++;
      if(i>26){ //只有0~25格
          i=0;
      }
    }

}
int f(char *data){
	int i;
	i = data[0] - 'A';
	return i;
}


int main(void) {
	setvbuf(stdout, NULL, _IONBF, 0);
	setvbuf(stderr, NULL, _IONBF, 0);

	char data[26];
	int i = 0;
	p_hash_t h; //hash table
	h = Create();

	for(i=0;i<26;i++){
		scanf("%s",data);
		Addentry(h,data); //add data into hash table
	}
	for(i=0;i<26;i++){
		printf("%3d %3d %s\n",i,h->hash_table[i].key,h->hash_table[i].data);
	}
	return 0;
}
