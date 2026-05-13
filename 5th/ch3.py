# -----------------------------------------
# ONLINE SHOPPING CHATBOT
# -----------------------------------------



# -----------------------------------------
# FUNCTION DEFINITION
# -----------------------------------------

# def keyword is used to create function

# shopping_chatbot is function name

def shopping_chatbot():



    # -----------------------------------------
    # WELCOME MESSAGE
    # -----------------------------------------

    # print() displays output on screen

    print("🛍️ Welcome to Online Shopping Assistant")



    # \n means new line

    print("Type 'exit' to close chatbot\n")



    # -----------------------------------------
    # INFINITE LOOP
    # -----------------------------------------

    # while True means:
    # loop runs continuously

    while True:



        # -----------------------------------------
        # USER INPUT
        # -----------------------------------------

        # input() takes input from user

        # .lower() converts text into lowercase

        # Example:
        # HELLO -> hello

        user = input("You: ").lower()



        # -----------------------------------------
        # GREETING CONDITION
        # -----------------------------------------

        # Checks:
        # if user types hello or hi

        if user == "hello" or user == "hi":



            # Bot reply

            print("Bot: Hello! Welcome to our shopping store.")



        # -----------------------------------------
        # PRODUCT CONDITION
        # -----------------------------------------

        # "product" in user

        # Checks whether word product
        # exists inside sentence

        # Example:
        # "show product"
        # "product details"

        elif "product" in user:



            # Product information

            print("Bot: We sell shoes, watches, mobiles, and laptops.")



        # -----------------------------------------
        # PRICE CONDITION
        # -----------------------------------------

        elif "price" in user:



            # Ask product name

            print("Bot: Please enter product name for price details.")



        # -----------------------------------------
        # OFFER CONDITION
        # -----------------------------------------

        # Checks both offer and discount words

        elif "offer" in user or "discount" in user:



            # Discount information

            print("Bot: Today we have 20% discount on electronics.")



        # -----------------------------------------
        # DELIVERY CONDITION
        # -----------------------------------------

        elif "delivery" in user:



            # Delivery details

            print("Bot: Delivery takes 2 to 4 working days.")



        # -----------------------------------------
        # PAYMENT CONDITION
        # -----------------------------------------

        elif "payment" in user:



            # Payment methods

            print("Bot: We accept UPI, Credit Card, Debit Card, and Cash on Delivery.")



        # -----------------------------------------
        # RETURN POLICY CONDITION
        # -----------------------------------------

        elif "return" in user:



            # Return policy

            print("Bot: Products can be returned within 7 days.")



        # -----------------------------------------
        # CUSTOMER SUPPORT CONDITION
        # -----------------------------------------

        # Checks support/help words

        elif "support" in user or "help" in user:



            # Customer care information

            print("Bot: Customer support number is 9876543210.")



        # -----------------------------------------
        # EXIT CONDITION
        # -----------------------------------------

        # If user types exit

        elif user == "exit":



            # Goodbye message

            print("Bot: Thank you for visiting our store!")



            # break terminates loop

            break



        # -----------------------------------------
        # DEFAULT CONDITION
        # -----------------------------------------

        # Runs if all conditions fail

        else:



            # Unknown query response

            print("Bot: Sorry, I did not understand your query.")




# -----------------------------------------
# FUNCTION CALL
# -----------------------------------------

# Starts chatbot execution

shopping_chatbot()