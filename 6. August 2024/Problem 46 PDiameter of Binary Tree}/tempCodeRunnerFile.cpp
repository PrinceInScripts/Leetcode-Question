int dia= levels(root->left)+levels(root->right);
        mxDia=max(mxDia,dia);
        diameterOfBinaryTree(root->left);
        diameterOfBinaryTree(root->right);
        return mxDia;