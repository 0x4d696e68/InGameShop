
/**************************************************************************************************

��ǰ(�Ӽ�) ��ü

���� ��ǰ�� �⺻ ������ �� ���� �Ӽ� ������ ������ �ִ�.
��ǰ ��ȣ�� ������ ���� �Ӽ��� �����Ͽ� �� ���� ��ǰ�� ǥ���ؾ� �Ѵ�.

**************************************************************************************************/

#pragma once

#include "include.h"
#include <map>

class CShopProduct
{
public:
	CShopProduct();
	virtual ~CShopProduct();

	bool SetProduct(std::string strdata);

public:	
	int		ProductSeq;											//  1. Product number
	char	ProductName[SHOPLIST_LENGTH_PRODUCTNAME];			//  2. product name
	char	PropertyName[SHOPLIST_LENGTH_PRODUCTPROPERTYNAME];	//  3. attribute name
	char	Value[SHOPLIST_LENGTH_PRODUCTVALUE];				//  4. attribute value
	char	UnitName[SHOPLIST_LENGTH_PRODUCTUNITNAME];			//  5. attribute unit name
	int		Price;												//  6. ��ǰ ����
	int		PriceSeq;											//  7. Product price number
	int		PropertyType;										//  8. Attribute Type (141: Item Attribute, 142: Price Attribute)
	int		MustFlag;											//  9. Required (145: required, 146: optional)
	int		vOrder;												// 10. ���� �Ӽ� ���� (1:���� �Ӽ�, 9:���� �Ӽ�)
	int		DeleteFlag;											// 11. ���� ���� (143: ����, 144: Ȱ��)
	int		StorageGroup;										// 12. ������ �׷� ����
	int		ShareFlag;											// 13. ServerType(���� ����) �� ������ ���� ���� �׸� ����
	char	InGamePackageID[SHOPLIST_LENGTH_INGAMEPACKAGEID];	// 14. ������ �ڵ�
	int		PropertySeq;										// 15. �Ӽ� �ڵ�
	int		ProductType;										// 16. ��ǰ ���� �ڵ�
	int		UnitType;											// 17. ���� �ڵ�
};