from faker import Faker
fake = Faker()
Faker.seed(1000)

for _ in range(10):
    print(fake.name())
