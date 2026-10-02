from functions import add

def test_add():
    lista = ["3FDF 25 Bistrita Cluj", "DSDF3 60 Mures Mamaia"]
    code = "3RFDF"
    duration = "30"
    dest_c = "Bistrita"
    dep_c = "Cluj"
    expected_result = ["3FDF 25 Bistrita Cluj", "DSDF3 60 Mures Mamaia", "3RFDF 30 Bistrita Cluj"]
    obtained_result = add(lista, code, duration, dest_c, dep_c)
    assert obtained_result == expected_result


def tests():
    test_add()