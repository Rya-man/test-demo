subtotal=0

bill = list(list())

for(i in 1:3){
  name = readline("Enter the name of the prodouct\t");
  price = as.numeric(readline("ENter the price of the product\t"));
  quantity = as.numeric((readline("ENter the quantity fo the product\t")))
  products = list("name"=name,"price"=price,"quantity"=quantity)
  subtotal = subtotal + (price*quantity)
  bill[[length(bill)+1]]=products
}
st = 1.08*subtotal
print("Name Price Quantity")
for(i in bill[2:length(bill)])
{
  print(paste(i[1],i[2],i[3]))
}
print(paste("total cost = ",subtotal))
print(paste("total cost after tax = ",st))
