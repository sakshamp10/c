import java.util.*;

class Admin{
    static private String password="1234";
    static private String uName="abcd";

    String getPassword(){
        return password;
    }
    String getuName(){
        return uName;
    }
}

class Customer{
    static private ArrayList<Customer> customerList= new ArrayList<Customer>();
    private String uName="";
    private String password="";

    String getuName(){
        return this.uName;
    }


    void setuName(String s){
        this.uName=s;
    }

    void setPassword(String s){
        this.password=s;
    }

    void addCust(Customer C){
        customerList.add(C);
    }

    int custSize(){
        return customerList.size();
    }

    Customer getcust(int i){
        return customerList.get(i);
    }

}

public class Main {
    static Scanner sc= new Scanner(System.in);
    static void admin(){
        Admin ad= new Admin();
        String p,u;
        System.out.println("ENTER USERNAME: ");
        u=sc.nextLine();
        System.out.println("ENTER PASSWORD: ");
        p=sc.nextLine();
        if(u.compareTo(ad.getuName())==0 && p.compareTo(ad.getPassword())==0) {
            while(true){
                System.out.println("\nWelcome " + u + "!\n");
                System.out.println("\nPlease choose any one of the following actions:\n" +
                        "1) Add category\n" +
                        "2) Delete category\n" +
                        "3) Add Product\n" +
                        "4) Delete Product\n" +
                        "5) Set Discount on Product\n" +
                        "6) Add giveaway deal\n" +
                        "7) Back\n");
                int n = sc.nextInt();
                if (n == 1){
                    ad.addCategory();
                }
                else if(n==2){
                    ad.delCategory();
                }
                else if(n==3){
                    ad.addProduct();
                }
                else if(n==4){
                    ad.delProduct();
                }
                else if(n==5){
                    ad.setDiscount();
                }
                else if(n==6){
                    ad.addGiveaway();
                }
                else if(n==7){
                    return;
                }
            }
        }
    }

    static void prodCatalog(){

    }

    static void signUp(){
        String n;
        String p;
        System.out.println("Enter Username: ");
        n=sc.nextLine();
        System.out.println("Enter Password: ");
        p=sc.nextLine();
        Customer C = new Customer();
        for(int i =0;i<C.custSize();i++){
            if(C.getcust(i).getuName().compareTo(n)==0){
                System.out.println("User Already Exists!\n");
                return;
            }
        }
        
    }

    static void logIn(){

    }
    static void customer(){
        while(true){
            System.out.println("\n1) Sign up\n" +
                    "2) Log in\n" +
                    "3) Back");
            int n=sc.nextInt();
            if(n==1){
                signUp();
            }
            else if(n==2){
                logIn();
            }
            else{
                return;
            }

        }
    }

    static void availableDeals(){

    }

    static void mainMenu(){
        while(true) {
            System.out.println("\nWELCOME TO FLIPZON\n" +
                    "1) Enter as Admin\n" +
                    "2) Explore the Product Catalog\n" +
                    "3) Show Available Deals\n" +
                    "4) Enter as Customer\n" +
                    "5) Exit the Application\n");
            int n;
            n = sc.nextInt();
            if (n == 1) {
                admin();
            } else if (n == 2) {
                prodCatalog();
            } else if (n == 3) {
                availableDeals();
            } else if (n == 4) {
                customer();
            } else if (n == 5) {
                return;
            }
        }
    }

    public static void main(String[] args) {
        String s;
        s= sc.nextLine();
        if(s.compareTo("enter")==0) {
            mainMenu();
        }
    }
}
