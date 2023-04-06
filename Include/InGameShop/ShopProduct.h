
/**************************************************************************************************

상품(속성) 객체

현재 상품의 기본 정보와 한 가지 속성 정보를 가지고 있다.
상품 번호가 동일한 여러 속성을 조합하여 한 가지 상품을 표현해야 한다.

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
	int		Price;												//  6. 상품 가격
	int		PriceSeq;											//  7. Product price number
	int		PropertyType;										//  8. Attribute Type (141: Item Attribute, 142: Price Attribute)
	int		MustFlag;											//  9. Required (145: required, 146: optional)
	int		vOrder;												// 10. 메인 속성 구분 (1:메인 속성, 9:서브 속성)
	int		DeleteFlag;											// 11. 삭제 여부 (143: 삭제, 144: 활성)
	int		StorageGroup;										// 12. 보관함 그룹 유형
	int		ShareFlag;											// 13. ServerType(서버 유형) 별 보관함 노출 공유 항목 여부
	char	InGamePackageID[SHOPLIST_LENGTH_INGAMEPACKAGEID];	// 14. 아이템 코드
	int		PropertySeq;										// 15. 속성 코드
	int		ProductType;										// 16. 상품 유형 코드
	int		UnitType;											// 17. 단위 코드
};