main: main.o command.o add_subject.o add_subject_helpers.o remove_subject.o \
  remove_subject_helpers.o util.o add_todo_helpers.o add_todo.o clear_subject.o \
  clear_subject_helpers.o print_subject.o print_subject_helpers.o reset.o \
  remove_todo.o remove_todo_helpers.o random_todo.o update.o update_helpers.o \
  display_subjects.o

add_subject.o: add_subject.c util.h add_subject.h add_subject_helpers.h \
 remove_subject_helpers.h

add_subject_helpers.o: add_subject_helpers.c util.h add_subject_helpers.h

add_todo.o: add_todo.c add_todo.h util.h add_todo_helpers.h \
 print_subject_helpers.h

add_todo_helpers.o: add_todo_helpers.c add_todo_helpers.h util.h

clear_subject.o: clear_subject.c clear_subject.h util.h \
 remove_subject_helpers.h clear_subject_helpers.h

clear_subject_helpers.o: clear_subject_helpers.c clear_subject_helpers.h \
 util.h

command.o: command.c command.h util.h

display_subjects.o: display_subjects.c display_subjects.h util.h


main.o: main.c command.h util.h add_subject.h remove_subject.h add_todo.h \
 clear_subject.h print_subject.h

print_subject.o: print_subject.c print_subject.h print_subject_helpers.h \
 util.h

print_subject_helpers.o: print_subject_helpers.c util.h

random_todo.o: random_todo.c random_todo.h util.h

remove_subject.o: remove_subject.c remove_subject.h util.h \
 remove_subject_helpers.h

remove_subject_helpers.o: remove_subject_helpers.c \
 remove_subject_helpers.h util.h

remove_todo.o: remove_todo.c util.h remove_todo.h

remove_todo_helpers.o: remove_todo_helpers.c util.h remove_todo_helpers.h


reset.o: reset.c reset.h util.h

update.o: update.c update_helpers.h update.h

update_helpers.o: update_helpers.c update_helpers.h util.h

util.o: util.c util.h

