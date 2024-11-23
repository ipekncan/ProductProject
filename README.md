# Product Management with Linked List

This Project is my homework for Aydin Adnan Menderes University.

## Overview

This C program provides a simple product management system implemented using a linked list data structure. It allows users to perform the following operations on a list of products:

Add a new product.

Remove an existing product by name.
Display all products in the list sorted by quantity.
The linked list is sorted in ascending order by quantity whenever a new product is added.

## Features

Add New Product: Users can input a product's quantity, name, category, and price. The new product is added to the list in numerical order based on quantity.

Remove Product: Users can remove a product from the list by specifying its name.

Display Product List: Displays all the products in the list, sorted by their quantity.

Menu-Driven Interface: The program operates through a simple text-based menu.

Product Record Structure

Each product in the list is represented by a Node structure with the following properties:

##### Quantity: The number of items available.
##### Product Name: The name of the product.
##### Product Category: The category the product belongs to (e.g., Food, Beverage).
##### Product Price: The price of the product.

## Usage
Main Menu Options:
1)Add a New Product
The user will be prompted to enter the product details: Quantity, Name, Category, and Price. The new product will be inserted into the list in ascending order by quantity.

2)Remove a Product
The user can remove a product by entering its name. If the product exists in the list, it will be deleted.

3)Display All Products
This option prints all the products in the list sorted by quantity in ascending order.

4)Exit
Exits the program.
