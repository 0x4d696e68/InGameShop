
/**************************************************************************************************

All products (attributes) list object

You can get product (property) objects sequentially using an iterator.
You can get the product (property) object by using the product number.
You can get the product (property) object using the product number and price number.

**************************************************************************************************/

#pragma once

#include "ShopProduct.h"

class CShopProductList
{
public:
	CShopProductList(void);
	~CShopProductList(void);

	void Clear();	
	int GetSize();	

	virtual void Append(CShopProduct product);

	void SetFirst();
	bool GetNext(CShopProduct& product);

	void SetProductSeqFirst(int ProductSeq);				// First position in the list of products (attributes) of the product number
	bool GetProductSeqNext(CShopProduct& product);			// Get the product (attribute) object and place it in the next product (attribute)

	void SetPriceSeqFirst(int ProductSeq, int PriceSeq);	// The first position in the list of products (attributes) by the combination of the corresponding product number and price number
	bool GetPriceSeqNext(CShopProduct& product);			// Get the product (attribute) object and place it in the next product (attribute)

protected:	
	int	PriceSeqKey;
	std::multimap<int, CShopProduct> m_Products;	
	std::multimap<int, CShopProduct>::iterator m_ProductIter;
	std::multimap<int, CShopProduct>::iterator m_ProductSeqIter;
	std::multimap<int, CShopProduct>::iterator m_PriceSeqIter;	
	std::pair<std::multimap<int, CShopProduct>::iterator, std::multimap<int, CShopProduct>::iterator> m_ProductRange;
	std::pair<std::multimap<int, CShopProduct>::iterator, std::multimap<int, CShopProduct>::iterator> m_PriceRange;
};
