# 5th Practical - Customer Support Chatbot with GUI
import tkinter as tk
from tkinter import scrolledtext


# Function to process user message
def chatbot_response():
    user = user_input.get().lower()
    chat_window.insert(tk.END, "You: " + user + "\n")

    if user == "hello" or user == "hi":
        response = "Hello! How can I help you today?"

    elif "product" in user:
        response = "We have mobiles, laptops, and headphones available."

    elif "price" in user:
        response = "Please tell me the product name for pricing information."

    elif "order" in user:
        response = "Please provide your order ID to check status."

    elif "delivery" in user:
        response = "Delivery usually takes 3 to 5 business days."

    elif "return" in user:
        response = "Products can be returned within 7 days of delivery."

    elif "payment" in user:
        response = "We support UPI, Debit Card, Credit Card, and Net Banking."

    elif user == "bye":
        response = "Thank you for visiting. Have a great day!"
        chat_window.insert(tk.END, "Bot: " + response + "\n")
        root.after(2000, root.destroy)  # Close app after 2 sec
        return

    else:
        response = "Sorry, I didn't understand. Please try again."

    chat_window.insert(tk.END, "Bot: " + response + "\n\n")

    user_input.delete(0, tk.END)


# Create main window
root = tk.Tk()
root.title("Customer Support Chatbot")
root.geometry("500x400")

# Chat display area
chat_window = scrolledtext.ScrolledText(root, wrap=tk.WORD, width=60, height=20)
chat_window.pack(padx=10, pady=10)

# Input field
user_input = tk.Entry(root, width=40, font=("Arial", 12))
user_input.pack(side=tk.LEFT, padx=10, pady=10)

# Send button
send_button = tk.Button(root, text="Send", command=chatbot_response)
send_button.pack(side=tk.LEFT, padx=5)

# Run GUI
root.mainloop()