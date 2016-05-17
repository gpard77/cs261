	int bucket = stringHash2(k)%ht->tableSize;
	struct hashLink *cur;
	struct hashLink *prev;
	if(ht->table[bucket] == 0){
		return 0;
	}else{
		cur=ht->table[bucket];
		prev=ht->table[bucket];
		while(cur!=0){
			if(strcmp(cur->key,k)==0){
				return &(cur->value);  
			}else{
				prev=cur;
				cur=cur->next;
			} 
		}
		return 0;
	}