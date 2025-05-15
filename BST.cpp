//*********************************************************
// Mètodes privats auxiliars
//*********************************************************
template <typename T>
void BST<T>::clear(Item *node) 
{
	if (node != nullptr) {
		clear(node->left);
		clear(node->right);
		delete node;
	}
}
//*********************************************************
/* Pre: Cert */
/* Post: Afegeix un node nou amb el valor
  rebut per paràmetre a la jerarquia de
  nodes apuntada per 'node', mantenint
  les propietats de BST */
template <typename T>
typename BST<T>::Item* BST<T>::insert(Item *node, const T& d) 
{  // CD1:Si node->data==d , ¿no se insertan duplicados? <<--
     if (node == nullptr){//CD2: :l'abre es buid
        node = new Item(d, nullptr, nullptr);
    } 
    else if (node->data>d) {// d es mes petita que la node->dada (el valor que apunta el punter node)
        node->left = insert(node->left, d);
    } 
    else if (node->data<d) {//d es mes gran que la node->dada (el valor que apunta el punter node)
        node->right = insert(node->right, d);
    }
    return node;
}
//*********************************************************
/* Pre: Cert */
/* Post: El resultat és el node de la jerarquia
 de nodes apuntada per 'node', amb el mateix
  valor que el valor rebut per paràmetre */
template <typename T>
typename BST<T>::Item* BST<T>::find(Item *node, const T& d) const 
{
	// CD:l'abre es buid o d==node->dada (el valor(freq) de d es igual al 
	// valor que apunta le punter node)
	Item*res=nullptr;
    if (node == nullptr or node->data == d){
        res=node;
    }
    // d es mes gran que la node->dada (el valor que apunta el punter node)
    if (node->data < d){
        res=find(node->right, d);
    }
    else{// d es mes petita que la node->dada (el valor que apunta el punter node)
    res=find(node->left, d);
    } 
    return res;	
}

//*********************************************************
// Constructors
//*********************************************************
template <typename T>
BST<T>::BST() {
	root = nullptr;
}

//*********************************************************
// Destructor
//*********************************************************
template <typename T>
BST<T>::~BST() 
{ 
	clear(root); 
}

//*********************************************************
// Modificadors
//*********************************************************
template <typename T>
void BST<T>::insert(const T& d) 
{ 
	root = insert(root, d); 
}

//*********************************************************
// Consultors
//*********************************************************
template <typename T>
pair<bool, T> BST<T>::find(const T& d) const 
{ 
	pair<bool, T> res = make_pair(false, d);
	Item* node = find(root, d);
	if (node != NULL) {
			res.first = true;
			res.second = node->data;
	}
	return res;
}
