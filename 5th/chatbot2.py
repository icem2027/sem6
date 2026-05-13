# -----------------------------------------
# ONLINE SHOPPING CHATBOT
# -----------------------------------------

# Function Definition

def shopping_chatbot():



    # Welcome Message

    print("🛍️ Welcome to Online Shopping Assistant")
    print("Type 'exit' to close chatbot\n")



    # Infinite loop

    while True:



        # Take user input

        user = input("You: ").lower()



        # Greeting condition

        if user == "hello" or user == "hi":


            print("Bot: Hello! Welcome to our shopping store.")



        # Product condition

        elif "product" in user:


            print("Bot: We sell shoes, watches, mobiles, and laptops.")



        # Price condition

        elif "price" in user:


            print("Bot: Please enter product name for price details.")



        # Offer condition

        elif "offer" in user or "discount" in user:


            print("Bot: Today we have 20% discount on electronics.")



        # Delivery condition

        elif "delivery" in user:


            print("Bot: Delivery takes 2 to 4 working days.")



        # Payment condition

        elif "payment" in user:


            print("Bot: We accept UPI, Credit Card, Debit Card, and Cash on Delivery.")



        # Return policy

        elif "return" in user:


            print("Bot: Products can be returned within 7 days.")



        # Customer care

        elif "support" in user or "help" in user:


            print("Bot: Customer support number is 9876543210.")



        # Exit condition

        elif user == "exit":


            print("Bot: Thank you for visiting our store!")
            break



        # Default condition

        else:


            print("Bot: Sorry, I did not understand your query.")




# Function Call

shopping_chatbot()