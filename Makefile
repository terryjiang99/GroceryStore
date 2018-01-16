OBJ = main.o InvControl.o Store.o Product.o UI.o ProdList.o Customer.o PurchArray.o Purchase.o OrderArray.o Order.o OrderServer.o Bakery.o CoffeeTea.o Dairy.o Date.o Meat.o MiscGoods.o NonPerishable.o NonTaxable.o Perishable.o Taxable.o TaxationBehaviour.o ExpirationBehaviour.o

cushop:	$(OBJ)
	g++ -o cushop $(OBJ)

main.o:	main.cc 
	g++ -c main.cc

InvControl.o:	InvControl.cc InvControl.h
	g++ -c InvControl.cc

UI.o:	UI.cc UI.h 
	g++ -c UI.cc

Store.o:	Store.cc Store.h  
	g++ -c Store.cc

Product.o:	Product.cc Product.h 
	g++ -c Product.cc

ProdList.o:	ProdList.cc ProdList.h 
	g++ -c ProdList.cc
	
PurchArray.o: PurchArray.cc PurchArray.h defs.h
	g++ -c PurchArray.cc
	
Purchase.o: Purchase.cc Purchase.h
	g++ -c Purchase.cc

Customer.o:	Customer.cc Customer.h
	g++ -c Customer.cc

OrderArray.o: OrderArray.cc OrderArray.h defs.h
	g++ -c OrderArray.cc

Order.o: Order.cc Order.h
	g++ -c Order.cc

OrderServer.o: OrderServer.cc OrderServer.h
	g++ -c OrderServer.cc

Date.o: Date.cc Date.h
	g++ -c Date.cc

Bakery.o: Bakery.cc Bakery.h Perishable.h Taxable.h Product.h
	g++ -c Bakery.cc

CoffeeTea.o: CoffeeTea.cc CoffeeTea.h NonPerishable.h Taxable.h Product.h
	g++ -c CoffeeTea.cc

Dairy.o: Dairy.cc Dairy.h Perishable.h NonTaxable.h Product.h
	g++ -c Dairy.cc

Meat.o: Meat.cc Meat.h Perishable.h NonTaxable.h Product.h
	g++ -c Meat.cc

MiscGoods.o: MiscGoods.cc MiscGoods.h NonPerishable.h Taxable.h Product.h
	g++ -c MiscGoods.cc

NonPerishable.o: NonPerishable.cc NonPerishable.h Product.h
	g++ -c NonPerishable.cc

NonTaxable.o: NonTaxable.cc NonTaxable.h Product.h
	g++ -c NonTaxable.cc

Perishable.o: Perishable.cc Perishable.h Product.h
	g++ -c Perishable.cc 

Taxable.o: Taxable.cc Taxable.h Product.h
	g++ -c Taxable.cc

TaxationBehaviour.o: TaxationBehaviour.cc TaxationBehaviour.h
	g++ -c TaxationBehaviour.cc

ExpirationBehaviour.o: ExpirationBehaviour.cc ExpirationBehaviour.h
	g++ -c ExpirationBehaviour.cc

clean:
	rm -f $(OBJ) cushop
