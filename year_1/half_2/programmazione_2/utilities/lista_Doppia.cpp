
lista esame(elem* &e){
    
    int inf=e->inf;
    while(e->prev!=NULL)
        e=prev(e);

    lista l2=NULL;
    lista precedente=NULL;
    lista precedente_min=NULL;
    lista l_temp=e;

    while(l_temp!=NULL){
        if(head(l_temp)<=inf){
            if(precedente==NULL){
                e=tail(e);
                e->prev=NULL;
            }
            else{
                precedente->pun=tail(l_temp);
                precedente->pun->prev=precedente;
            }
            if(precedente_min==NULL){
                precedente_min=l2=l_temp;
                precedente_min->prev=l2->prev=NULL;
            }
            else{
                precedente_min->pun=l_temp;
                precedente_min->pun->prev=precedente_min;
                precedente_min=l_temp;
            }
        }
        else
            precedente=l_temp;

        l_temp=tail(l_temp); 
    }
    precedente_min->pun=NULL;
    return l2;
}

NULL<-e->5<->4<->2<->3
l2->NULL
precedente->
precedente_min->
l_temp->1<->5<->4<->2<->3