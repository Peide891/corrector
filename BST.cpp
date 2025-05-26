//*********************************************************
// Mètodes privats auxiliars
//*********************************************************
/* Pre: cert */
/* Post: Allibera tota la memòria dels nodes a partir de 'node',
   eliminant recursivament els fills esquerre i dret. */
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
{  
	// CD1:Si node->data==d, no fa res
    if (node == nullptr){//CD2: :l'abre es buid
        node = new Item(d, nullptr, nullptr);
    } 
    else if (node->data.getPar()>d.getPar()) {// d < node->data → anar esquerra
        node->left = insert(node->left, d);
    // H.I.: insert(node, d) insereix d a la part esquerra en el subarbre arrelat a node,
    //       mantenint la propietat BST (tots els nodes a l'esquerra < node < dreta).
    // Fita: altura del subarbre esquerra node. 
    } 
    else if (node->data.getPar()<d.getPar()) {// d > node->data → anar dreta
        node->right = insert(node->right, d);
    // H.I.: insert(node, d) insereix d a la part dreta en el subarbre arrelat a node,
    //       mantenint la propietat BST (tots els nodes a l'esquerra < node < dreta).
    // Fita: altura del subarbre dret node. 
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
    if (node == nullptr or node->data.getPar() == d.getPar()){
        res=node;
    }
    else{
		// d es mes gran que la node->dada (el valor que apunta el punter node)
		if (node->data.getPar() < d.getPar()){
			res=find(node->right, d);
			// H.I.: find(node, d) cerca la d en la part dreta del el subarbre arrelat a node,
			//seguint la propietat BST (si d < node → esquerra, si d > node → dreta).
			// Fita: numbre del elements del subarbre dret.
		}
		else{// d es mes petita que la node->dada (el valor que apunta el punter node)
		res=find(node->left, d);
		    // H.I.: find(node, d) cerca la d en la part dreta del el subarbre arrelat a node,
			//seguint la propietat BST (si d < node → esquerra, si d > node → dreta).
			// Fita: numbre del elements del subarbre esquerra
		} 
    }
    return res;	
}

//*********************************************************
// Constructors
//*********************************************************
/* Pre: cert */
/* Post: Crea un arbre buit (root = nullptr). */
template <typename T>
BST<T>::BST() {
	root = nullptr;
}

//*********************************************************
// Destructor
//*********************************************************
/* Pre: cert */
/* Post: Allibera tota la memòria de l’arbre. */
template <typename T>
BST<T>::~BST() 
{ 
	clear(root); 
}

//*********************************************************
// Modificadors
//*********************************************************
/* Pre: cert */
/* Post: Insereix l’element d a l’arbre, si no hi és ja. */
template <typename T>
void BST<T>::insert(const T& d) 
{ 
	root = insert(root, d); 
}

//*********************************************************
// Consultors
//*********************************************************
/* Pre: cert */
/* Post: Retorna (true, x) si x==d és a l’arbre, (false, d) si no. */
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
