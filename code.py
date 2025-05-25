mport json
import os
import datetime
from colorama import Fore, Style, init

init(autoreset=True)

DATA_FILE = 'tasks.json'

class Task:
    def __init__(self, title, description='', due_date=None, status='pending'):
        self.title = title
        self.description = description
        self.due_date = due_date
        self.status = status

    def to_dict(self):
        return {
            'title': self.title,
            'description': self.description,
            'due_date': self.due_date,
            'status': self.status
        }

    @staticmethod
    def from_dict(data):
        return Task(
            title=data['title'],
            description=data.get('description', ''),
            due_date=data.get('due_date', None),
            status=data.get('status', 'pending')
        )

def load_tasks():
    if not os.path.exists(DATA_FILE):
        return []

    with open(DATA_FILE, 'r') as f:
        data = json.load(f)
        return [Task.from_dict(item) for item in data]

def save_tasks(tasks):
    with open(DATA_FILE, 'w') as f:
        json.dump([task.to_dict() for task in tasks], f, indent=4)

def display_tasks(tasks):
    if not tasks:
        print(Fore.YELLOW + "No tasks found.")
        return
    for i, task in enumerate(tasks, 1):
        status_color = Fore.GREEN if task.status == 'done' else Fore.RED
        print(f"{i}. {status_color}{task.title} {Style.RESET_ALL}- {task.description} [Due: {task.due_date or 'N/A'}] [{task.status}]")

def add_task(tasks):
    title = input("Title: ").strip()
    description = input("Description: ").strip()
    due_date = input("Due Date (YYYY-MM-DD): ").strip()
    if due_date == '':
        due_date = None
    tasks.append(Task(title, description, due_date))
    print(Fore.GREEN + "Task added successfully!")

def delete_task(tasks):
    display_tasks(tasks)
    idx = int(input("Enter the task number to delete: "))
    if 0 < idx <= len(tasks):
        removed = tasks.pop(idx - 1)
        print(Fore.YELLOW + f"Deleted task: {removed.title}")
    else:
        print(Fore.RED + "Invalid index.")

def mark_task_done(tasks):
    display_tasks(tasks)
    idx = int(input("Enter the task number to mark as done: "))
    if 0 < idx <= len(tasks):
        tasks[idx - 1].status = 'done'
        print(Fore.GREEN + f"Marked '{tasks[idx - 1].title}' as done.")
    else:
        print(Fore.RED + "Invalid index.")

def edit_task(tasks):
    display_tasks(tasks)
    idx = int(input("Enter task number to edit: "))
    if 0 < idx <= len(tasks):
        task = tasks[idx - 1]
        print(f"Editing '{task.title}'")
        task.title = input(f"New title (Enter to keep '{task.title}'): ") or task.title
        task.description = input(f"New description (Enter to keep current): ") or task.description
        new_due = input(f"New due date (YYYY-MM-DD or Enter to keep '{task.due_date}'): ")
        if new_due:
            task.due_date = new_due
        print(Fore.GREEN + "Task updated.")
    else:
        print(Fore.RED + "Invalid index.")

def search_tasks(tasks):
    keyword = input("Search keyword: ").lower()
    results = [task for task in tasks if keyword in task.title.lower() or keyword in task.description.lower()]
    print(Fore.CYAN + f"\nFound {len(results)} task(s) matching '{keyword}':")
    display_tasks(results)

def sort_tasks(tasks):
    tasks.sort(key=lambda x: x.due_date or '', reverse=False)
    print(Fore.GREEN + "Tasks sorted by due date.")

def filter_tasks(tasks):
    status = input("Enter status to filter (pending/done): ").strip().lower()
    filtered = [task for task in tasks if task.status == status]
    print(Fore.CYAN + f"\nFiltered tasks with status '{status}':")
    display_tasks(filtered)

def clear_tasks(tasks):
    confirm = input(Fore.RED + "Are you sure you want to delete ALL tasks? (y/n): ")
    if confirm.lower() == 'y':
        tasks.clear()
        print(Fore.YELLOW + "All tasks cleared.")

def show_menu():
    print(Fore.CYAN + "\n==== TO-DO LIST MENU ====")
    print("1. View Tasks")
    print("2. Add Task")
    print("3. Edit Task")
    print("4. Delete Task")
    print("5. Mark Task as Done")
    print("6. Search Tasks")
    print("7. Sort by Due Date")
    print("8. Filter by Status")
    print("9. Clear All Tasks")
    print("0. Exit")
    print("=========================")

def main():
    tasks = load_tasks()

    while True:
        show_menu()
        choice = input("Enter your choice: ").strip()

        if choice == '1':
            display_tasks(tasks)
        elif choice == '2':
            add_task(tasks)
        elif choice == '3':
            edit_task(tasks)
        elif choice == '4':
            delete_task(tasks)
        elif choice == '5':
            mark_task_done(tasks)
        elif choice == '6':
            search_tasks(tasks)
        elif choice == '7':
            sort_tasks(tasks)
        elif choice == '8':
            filter_tasks(tasks)
        elif choice == '9':
            clear_tasks(tasks)
        elif choice == '0':
            save_tasks(tasks)
            print(Fore.MAGENTA + "Goodbye!")
            break
        else:
            print(Fore.RED + "Invalid choice. Try again.")

if __name__ == '__main__':
    main()
